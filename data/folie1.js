json1 = `{
	"frame": [
		{
			"id": 1,
			"y_pos": 80,
			"y_lang": 0,
			"seite": 1,
			"knopf": [
				{
					"id": 1,
					"x_pos": 10,
					"y_pos": 0,
					"x_lang": 200,
					"y_lang": 100,
					"fu": "WHITE",
					"fh": "BLACK",
					"ft": "WHITE",
					"text": "per QR verbinden",
					"befehle": [
						"Hallo"
					],
					"gt": 2
				},
				{
					"id": 2,
					"x_pos": 60,
					"y_pos": 300,
					"x_lang": 200,
					"y_lang": 100,
					"fu": "WHITE",
					"fh": "RED",
					"ft": "WHITE",
					"text": "MQTT_Verbinden",
					"befehle": [
						"start_mqtt_client",
						"folie.o_frame[1].o_knopf[2].andere_label_str_parameter('fh','GREEN')"
					],
					"gt": 2
				}
			],
			"menu": [
				{
					"id": 1,
					"x_pos": 60,
					"y_pos": 200,
					"x_lang": 200,
					"y_lang": 100,
					"fu": "WHITE",
					"fh": "ORANGE",
					"ft": "WHITE",
					"text": "Hallo Welt",
					"punkte": [
						"5 ms",
						"10 ms",
						"100 ms",
						"500 ms",
						"1000 ms",
						"5000 ms",
						"10000 ms"
					],
					"gt": 2
				}
			],
			"schalter": [
				{
					"id": 1,
					"x_pos": 100,
					"y_pos": 100,
					"x_lang": 200,
					"y_lang": 100,
					"fu": "PURPLE",
					"fh": "NAVY",
					"ft": "WHITE",
					"text": "Lampe",
					"start": true,
					"gt": 2
				}
			]
			
		},
		{
			"id": 2,
			"y_pos": 580,
			"y_lang": 0,
			"seite": 1,
			"knopf": [
				{
					"id": 1,
					"text": "CSM Abschalten",
					"befehle": [
						"Hallo"
					],
					"gt": 2
				},
				{
					"id": 2,
					
					"text": "CSM OS OTA Update",
					"befehle": [
						"sende_mqtt",
						"csm_eingang"
					],
					"gt": 2
				}
			],
			
			"label": [
				{
					"id": 1,
					"text": "Ladestand: 100%",
					"gt": 4
				},{
					"id": 2,
					"text": "Energieversorgung:",
					"gt": 4
				},{
					"id": 3,
					"text": "Netzbetrieb",
					"gt": 4
				},{
					"id": 4,
					"text": "CSM OS Version: CSM_OS_2.0.11",
					"gt": 4
				},{
					"id": 5,
					"text": "CSM_OS_2.0.11",
					"gt": 4
				},{
					"id": 6,
					"text": "Hardware: CSM V3.2",
					"gt": 4
				}
			]
		},
		{
			"id": 3,
			"y_pos": 580,
			"y_lang": 0,
			"seite": 1,
			"knopf": [
				{
					"id": 1,
					"text": "nach Sensor suchen",
					"befehle": [
						"Hallo"
					],
					"gt": 2
				}
			],
			
			"label": [
				{
					"id": 1,
					"text": "aktueller Sensor:",
					"gt": 4
				},	{
					"id": 2,
					"text": "-",
					"gt": 4
				},				{
					"id": 3,
					"text": "Messdaten: Keine",
					"gt": 2
				}
			]
		},
		{
			"id": 4,
			"y_pos": 580,
			"y_lang": 0,
			"seite": 1,
			"knopf": [
				{
					"id": 1,
					"text": "nach Sensor suchen",
					"befehle": [
						"Hallo"
					],
					"gt": 2
				}
			],
			
			"label": [
				{
					"id": 1,
					"text": "aktueller Sensor:",
					"gt": 4
				},	{
					"id": 2,
					"text": "-",
					"gt": 4
				},				{
					"id": 3,
					"text": "Messdaten: Keine",
					"gt": 2
				}
			]
		}
	]
	
}`;

json2 = `
    {
        "frame": [
            {
                "id": 1,
                "y_pos": 70,
                "y_lang": 0,
                "seite": 1,
                
                "label": [
                    {
                        "id": 1,
                        "x_pos": 10,
                        "y_pos": 0,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "WHITE",
                        "ft": "BLACK",
                        "text": "abc "
                    },{
                        "id": 2,
                        "x_pos": 10,
                        "y_pos": 50,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "WHITE",
                        "ft": "BLACK",
                        "text": " "
                    },{
                        "id": 3,
                        "x_pos": 10,
                        "y_pos": 100,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "WHITE",
                        "ft": "BLACK",
                        "text": " "
                    },{
                        "id": 4,
                        "x_pos": 10,
                        "y_pos": 150,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "WHITE",
                        "ft": "BLACK",
                        "text": " "
                    },{
                        "id": 5,
                        "x_pos": 10,
                        "y_pos": 200,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "WHITE",
                        "ft": "BLACK",
                        "text": " "
                    },{
                        "id": 6,
                        "x_pos": 10,
                        "y_pos": 250,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "WHITE",
                        "ft": "BLACK",
                        "text": " "
                    },{
                        "id": 7,
                        "x_pos": 10,
                        "y_pos": 300,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "WHITE",
                        "ft": "BLACK",
                        "text": " "
                    }
                ]
            },{
                "id": 2,
                "y_pos": 70,
                "y_lang": 0,
                "seite": 1,
                
                "label": [
                    {
                        "id": 1,
                        "x_pos": 155,
                        "y_pos": 0,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "BLACK",
                        "ft": "WHITE",
                        "text": " "
                    },{
                        "id": 2,
                        "x_pos": 155,
                        "y_pos": 50,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "BLACK",
                        "ft": "WHITE",
                        "text": " "
                    },{
                        "id": 3,
                        "x_pos": 155,
                        "y_pos": 100,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "BLACK",
                        "ft": "WHITE",
                        "text": " "
                    },{
                        "id": 4,
                        "x_pos": 155,
                        "y_pos": 150,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "BLACK",
                        "ft": "WHITE",
                        "text": " "
                    },{
                        "id": 5,
                        "x_pos": 155,
                        "y_pos": 200,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "BLACK",
                        "ft": "WHITE",
                        "text": " "
                    },{
                        "id": 6,
                        "x_pos": 155,
                        "y_pos": 250,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "BLACK",
                        "ft": "WHITE",
                        "text": " "
                    },{
                        "id": 7,
                        "x_pos": 155,
                        "y_pos": 300,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "BLACK",
                        "ft": "WHITE",
                        "text": " "
                    }
                ]
            }
            
        ]
        
    

}`;

json3 = `
    {
        "frame": [
            {
                "id": 3,
                "y_pos": 70,
                "y_lang": 0,
                "seite": 1,
                "knopf": [
                    {
                        "id": 1,
                        "x_pos": 10,
                        "y_pos": 0,
                        "x_lang": 200,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "BLACK",
                        "ft": "WHITE",
                        "text": "Direktausgabe",
                        "befehle": [
                            "offne_seite(2);"
                        ],
                        "gt": 2
                    },
                    {
                        "id": 2,
                        "x_pos": 10,
                        "y_pos": 50,
                        "x_lang": 200,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "BLACK",
                        "ft": "WHITE",
                        "text": "mit_QR_Verbinden",
                        "befehle": [
                            "mit_csm_verbinden_qr()"
                            
                        ],
                        "gt": 2
                    },
                    {
                        "id": 3,
                        "x_pos": 10,
                        "y_pos": 100,
                        "x_lang": 200,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "CYAN",
                        "ft": "WHITE",
                        "text": "MQTT_Verbinden",
                        "befehle": [
                            "start_mqtt_client",
                            "folie.o_frame[3].o_knopf[3].andere_label_str_parameter('fh','GREEN')",
                            "folie.o_frame[3].o_knopf[8].andere_label_str_parameter('fh','GREEN')"
                        ],
                        "gt": 2
                    },{
                        "id": 8,
                        "x_pos": 10,
                        "y_pos": 150,
                        "x_lang": 200,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "RED",
                        "ft": "WHITE",
                        "text": "MQTT_senden",
                        "befehle": [
                            "sende_mqtt('vom_CSM','knopf_betatigt');"
                        ],
                        "gt": 2
                    },{
                        "id": 4,
                        "x_pos": 0,
                        "y_pos": 300,
                        "x_lang": 50,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "BLACK",
                        "ft": "WHITE",
                        "text": "1",
                        "befehle": [
                            "schreib_helligkeitsdaten(2)"
                        ],
                        "gt": 2
                    },{
                        "id": 5,
                        "x_pos": 60,
                        "y_pos": 300,
                        "x_lang": 50,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "BLACK",
                        "ft": "WHITE",
                        "text": "4",
                        "befehle": [
                            "schreib_helligkeitsdaten(3)"
                        ],
                        "gt": 2
                    },{
                        "id": 6,
                        "x_pos": 120,
                        "y_pos": 300,
                        "x_lang": 50,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "BLACK",
                        "ft": "WHITE",
                        "text": "10",
                        "befehle": [
                            "schreib_helligkeitsdaten(4)"
                        ],
                        "gt": 2
                    },{
                        "id": 7,
                        "x_pos": 180,
                        "y_pos": 300,
                        "x_lang": 50,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "BLACK",
                        "ft": "WHITE",
                        "text": "100",
                        "befehle": [
                            "schreib_helligkeitsdaten(6)"
                        ],
                        "gt": 2
                    }
                ],
                "menu": [
                    {
                        "id": 1,
                        "x_pos": 60,
                        "y_pos": 200,
                        "x_lang": 200,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "ORANGE",
                        "ft": "WHITE",
                        "text": "Menu",
                        "punkte": [
                            "5 ms",
                            "10 ms",
                            "100 ms",
                            "500 ms",
                            "1000 ms",
                            "5000 ms",
                            "10000 ms"
                        ],
                        "gt": 2
                    }
                ],
                "schalter": [
                    {
                        "id": 1,
                        "x_pos": 100,
                        "y_pos": 250,
                        "x_lang": 200,
                        "y_lang": 50,
                        "fu": "PURPLE",
                        "fh": "NAVY",
                        "ft": "WHITE",
                        "text": "Lampe",
                        "start": true,
                        "gt": 2
                    }
                ]
                
            },
            {
                "id": 1,
                "y_pos": 70,
                "y_lang": 0,
                "seite": 2,
                
                "label": [
                    {
                        "id": 1,
                        "x_pos": 10,
                        "y_pos": 0,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "WHITE",
                        "ft": "BLACK",
                        "text": " "
                    },{
                        "id": 2,
                        "x_pos": 10,
                        "y_pos": 50,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "WHITE",
                        "ft": "BLACK",
                        "text": " "
                    },{
                        "id": 3,
                        "x_pos": 10,
                        "y_pos": 100,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "WHITE",
                        "ft": "BLACK",
                        "text": " "
                    },{
                        "id": 4,
                        "x_pos": 10,
                        "y_pos": 150,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "WHITE",
                        "ft": "BLACK",
                        "text": " "
                    },{
                        "id": 5,
                        "x_pos": 10,
                        "y_pos": 200,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "WHITE",
                        "ft": "BLACK",
                        "text": " "
                    },{
                        "id": 6,
                        "x_pos": 10,
                        "y_pos": 250,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "WHITE",
                        "ft": "BLACK",
                        "text": " "
                    },{
                        "id": 7,
                        "x_pos": 10,
                        "y_pos": 300,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "WHITE",
                        "ft": "BLACK",
                        "text": " "
                    }
                ]
            },{
                "id": 2,
                "y_pos": 70,
                "y_lang": 0,
                "seite": 2,
                
                "label": [
                    {
                        "id": 1,
                        "x_pos": 155,
                        "y_pos": 0,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "BLACK",
                        "ft": "WHITE",
                        "text": " "
                    },{
                        "id": 2,
                        "x_pos": 155,
                        "y_pos": 50,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "BLACK",
                        "ft": "WHITE",
                        "text": " "
                    },{
                        "id": 3,
                        "x_pos": 155,
                        "y_pos": 100,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "BLACK",
                        "ft": "WHITE",
                        "text": " "
                    },{
                        "id": 4,
                        "x_pos": 155,
                        "y_pos": 150,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "BLACK",
                        "ft": "WHITE",
                        "text": " "
                    },{
                        "id": 5,
                        "x_pos": 155,
                        "y_pos": 200,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "BLACK",
                        "ft": "WHITE",
                        "text": " "
                    },{
                        "id": 6,
                        "x_pos": 155,
                        "y_pos": 250,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "BLACK",
                        "ft": "WHITE",
                        "text": " "
                    },{
                        "id": 7,
                        "x_pos": 155,
                        "y_pos": 300,
                        "x_lang": 145,
                        "y_lang": 50,
                        "fu": "WHITE",
                        "fh": "BLACK",
                        "ft": "WHITE",
                        "text": " "
                    }
                ]
            },
            {
                "id": 4,
                "y_pos": 580,
                "y_lang": 0,
                "seite": 1,
                "knopf": [
                    {
                        "id": 1,
                        "text": "nach Sensor suchen",
                        "befehle": [
                            "Hallo"
                        ],
                        "gt": 2
                    }
                ],
                
                "label": [
                    {
                        "id": 1,
                        "text": "aktueller Sensor:",
                        "gt": 4
                    },	{
                        "id": 2,
                        "text": "-",
                        "gt": 4
                    },				{
                        "id": 3,
                        "text": "Messdaten: Keine",
                        "gt": 2
                    }
                ]
            }
        ]
        
    }
`;