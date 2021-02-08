# Sonos-Remote-Station
This is the source code of the Sonos-Remote-Station: https://twitter.com/tmjns92/status/1256179074495627264 

### How to start:
Make sure you're goint to integrate all the files into a PlatformIO project structure. Don't forget to edit these lines:

```c++
#define SSID "________" // Your WiFi SSID
#define PASSWORD "________" // Your WiFi Password

IPAddress g_MasterBedroomIP(192, 168, 8, 112); //Your Sonos Speaker IP
const char g_MasterBedroomID[] = "1CBBFW9E899ED"; //Your Sonos Speaker ID
```
