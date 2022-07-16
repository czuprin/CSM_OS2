
#include <Arduino.h>
#include <AsyncTCP.h>
#include <DNSServer.h>





#define TCP_SERVER_PORT 8000


static void handleData(void *arg, AsyncClient *client, void *data, size_t len)
{
  //Serial.printf("\n data received from client %s \n", client->remoteIP().toString().c_str());
  //Serial.write((uint8_t *)data, len);

  //our big json string test
  //String jsonString = "Test123";
  // reply to client
  //if (client->space() > strlen(jsonString.c_str()) && client->canSend())
  // {
  //  client->add(jsonString.c_str(), strlen(jsonString.c_str()));
  //client->send();
  //}
  char* eingabe = (char *)data;
  // Serial.println("");
  if (len > 2) {
    Serial.println("");
    String gesamt_befehl = "";
    Serial.println(len);
    for (int i = 0; i < len; i++) {
      gesamt_befehl = gesamt_befehl + eingabe[i];
    }
    Serial.println(gesamt_befehl);
    csm_befehl_hinzufugen(gesamt_befehl);
  }


}

static void handleError(void *arg, AsyncClient *client, int8_t error)
{
  Serial.printf("\n connection error %s from client %s \n", client->errorToString(error), client->remoteIP().toString().c_str());
}

static void handleDisconnect(void *arg, AsyncClient *client)
{
  Serial.printf("\n client %s disconnected \n", client->remoteIP().toString().c_str());
}

static void handleTimeOut(void *arg, AsyncClient *client, uint32_t time)
{
  Serial.printf("\n client ACK timeout ip: %s \n", client->remoteIP().toString().c_str());
}

static void handleNewClient(void *arg, AsyncClient *client)
{
  Serial.printf("\n new client has been connected to server, ip: %s", client->remoteIP().toString().c_str());
  // register events
  client->onData(&handleData, NULL);
  client->onError(&handleError, NULL);
  client->onDisconnect(&handleDisconnect, NULL);
  client->onTimeout(&handleTimeOut, NULL);
}





void init_tcp() {

  AsyncServer *server = new AsyncServer(TCP_SERVER_PORT); // start listening on tcp port 7050
  server->onClient(&handleNewClient, server);
  server->begin();
}
