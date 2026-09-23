#include <Arduino.h>
#include<Wifi.h>
#include "State.h"
#include "config.h"
#include "Peripherals.h"
#include "Network.h"
#include "Telemetry.h"
#include "model.h"
#include "edge_ai.h"
#include "optimization.h"
#include "rpc.h"
#include "attributes.h"



void setup()
{
    //initialize serial monitor
    Serial.begin(115200);
    // initialise sensor
    dht.begin();  
    //configure esp32 with real time
    configTime(0,0,"pool.ntp.org","time.nist.gov");
    //configure peripheral pins
    pinMode(BTN_PLUGIN , INPUT_PULLUP);
    pinMode(BTN_PLUGOUT , INPUT_PULLUP);
    pinMode(RELAY_PIN , OUTPUT);
    pinMode(LED_GREEN , OUTPUT);
    pinMode(LED_YELLOW , OUTPUT);
    pinMode(LED_RED , OUTPUT);


    //connect board to wifi
    connectWiFi();

    
    
    // Configure MQTT server
    mqtt.setServer(MQTT_SERVER, MQTT_PORT); // MQTT sever address and port number
    //set a call back upon receiving the data from the cloud
    mqtt.setCallback(mqttCallback);
    mqtt.setBufferSize(512);


    //connect board to the cloud
    connectMQTT();  // TOKEN and DEVICE_ID

}

unsigned long now;
unsigned long last_print;

void loop()
{
    //keep listening to the incoming request
    mqtt.loop();
    //push data for every 5 sec
    now = millis();
    if((now - last_print) > 5000)
    {
        last_print = now;
         // read data from senors  // voltage,current,power,bay_status
         sample_sensors();
         //run ai to get the prediction
         runEdgeAIInference(); 
          //decide load based on the predictions
          if(manualOverrideActive == 0)
          {
          runOptimization();
          }
         //publish the data
         publishTelemetry();
    }
    plug_status();
    updateLeds();
    
}

