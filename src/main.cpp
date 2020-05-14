#include <SonosUPnP.h>
#include <MicroXPath_P.h>
#include <WiFi.h>
#include <FastLED.h>
#include <TinyPICO.h>
//##################################################################//
#define NUM_LEDS 8
#define DATA_PIN 27
#define ETHERNET_ERROR_CONNECT "E: Connect"
#define SSID "xxx" //WiFi SSID
#define PASSWORD "xxx" //WiFi Password
//##################################################################//
void ethConnectError();
//##################################################################//
WiFiClient client;
SonosUPnP g_sonos = SonosUPnP(client, ethConnectError);
CRGB leds[NUM_LEDS];
TinyPICO tp = TinyPICO();
//Master Bedroom####################################################//
IPAddress g_MasterBedroomIP(000, 000, 0, 000); //Sonos Speaker IP
const char g_MasterBedroomID[] = "xxxxxxxxxxxxxx"; //Sonos Speaker ID
//Button Setup####################################################//
const int pin_array[] = {4, 14, 15};   
const int pin_count = sizeof(pin_array) / sizeof(int);

void ethConnectError(){
  Serial.println(ETHERNET_ERROR_CONNECT);
  Serial.println("Wifi died.");
}

void volumeControl(){
  //analogRead and map
  int val = analogRead(32);
  int numLedsToLight = map(val, 0, 4095, 0, NUM_LEDS);
  
  //FastLED
  FastLED.clear();
  for(int led = 0; led < numLedsToLight; led++) { 
    leds[led] = CRGB::Yellow; 
  }
  FastLED.show();
  
  //volumeControl
  int previousVolume = 0;
  unsigned long previousMillisPoti = 0; 
  const long delayReadingPoti = 100; 
  unsigned long currentMillisPoti = millis();

  if (currentMillisPoti - previousMillisPoti >= delayReadingPoti) {
    previousMillisPoti = currentMillisPoti;
    int currentVolume = map(val, 0, 4095, 0, 50);

    if(currentVolume > previousVolume + 1 || currentVolume  < previousVolume - 1){
      g_sonos.setVolume(g_MasterBedroomIP,currentVolume);
      //Serial.println(currentVolume);
    }
    previousVolume = currentVolume;
  }
}

void inputControl(){
  if (digitalRead(14) == HIGH){
     g_sonos.togglePause(g_MasterBedroomIP);
  }  
  else if(digitalRead(15) == HIGH){
    g_sonos.skip(g_MasterBedroomIP, SONOS_DIRECTION_FORWARD);
  } 
  else if(digitalRead(4) == HIGH){
    g_sonos.skip(g_MasterBedroomIP, SONOS_DIRECTION_BACKWARD);
  } 
}

int smoothOutVolume(){
  int value = 0;
  int numReadings = 10;
  for (int i = 0; i < numReadings; i++){
    value = value + analogRead(32);
    delay(1);
  }
  value = value / numReadings;
  value = value / 4;
  return value;
}

void setup(){ 
  Serial.begin(115200);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(50);

  for(int index = 0; index < 3; index++){
    pinMode(pin_array[index], INPUT);
  }

  WiFi.begin(SSID, PASSWORD);
    while (WiFi.status() != WL_CONNECTED){
      tp.DotStar_SetPixelColor( 220, 20, 60 );
      delay(500);
      Serial.print(".");
    }
  if (WiFi.status() == WL_CONNECTED){
    tp.DotStar_SetPixelColor( 255, 215, 0);
  }
}

void loop(){ 
  volumeControl();
  inputControl();
}