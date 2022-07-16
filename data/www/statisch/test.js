var gateway = `ws://${window.location.hostname}/ws`;
var websocket;
window.addEventListener('load', onload);

function onload(event) {
    initWebSocket();
}

function initWebSocket() {
    console.log('Trying to open a WebSocket connection…');
    websocket = new WebSocket(gateway);
    websocket.onclose = onClose;
    websocket.onmessage = onMessage;
}
function onClose(event) {
    console.log('Connection closed');
    setTimeout(initWebSocket, 2000);
}

function knopf_getruckt(e_label,e_knopf){
    websocket.send(e_label+":"+e_knopf);
  }

class c_label {

    constructor(text) {
        //let text = "";
        this._text = text;
    }
    get text() {
        return this._text;
      }
    
    set text(text) {
        this._text = text; // validation could be checked here such as only allowing non numerical values
      }


    play() {
      console.log(this.name, "plays")
    }
  }
  
  // Class that holds a collection of players and properties and functions for the group
  class c_frame {
    constructor(){
      this.o_label = []
      this.neu_label("");
      this.neu_label("");
      this.neu_label("");
      this.neu_label("");
      this.neu_label("");
      this.neu_label("");
      
    }
    // create a new player and save it in the collection
    neu_label(name){
      let p = new c_label(name)
      this.o_label.push(p);
      return p
    }
    get_label(poition){

        return this.o_label[poition].text
    }
    get allPlayers(){
      return this.o_label
    }
    // this could include summary stats like average score, etc. For simplicy, just the count for now
    get numberOfPlayers(){
        return this.o_label.length
    
    }

  }
  
  let o_label = new c_frame()
  
 // o_label.neu_label("Mark","a")
 // o_label.neu_label("Roger","7")
 //o_label.o_label[1].text = "1";
 //o_label.o_label[2].text = "4";
 //o_label.o_label[3].text = "2";

 o_label.o_label[4].text = "hallo";
 //document.getElementById("o_label.o_label[4].text").innerHTML =  o_label.o_label[4].text;
  console.log(o_label.o_label[4].text)

  // list all the players
  console.log(o_label.numberOfPlayers + " Players")
  console.log(o_label.allPlayers)
  
  
  // make them do something
  o_label.allPlayers.forEach(player => player.play())



function o_read(eingabe) 
{  
    
    if (s == 2){
        var txtFile = new XMLHttpRequest();  
        txtFile.open("GET", "/www/d.html", true);  
     
     txtFile.onreadystatechange = function()   
     {  
          if (txtFile.readyState === 4)   
          {  
               // Makes sure the document is ready to parse.  
               if (txtFile.status === 200)   
               {  
                    // Makes sure it's found the file.  
                    console.log( txtFile.responseText);  
               }  
          }  
     }  
     txtFile.send(null)  
}}  

