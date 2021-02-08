# Sonos-Remote-Station
This is the source code of the Sonos-Remote-Station: https://twitter.com/tmjns92/status/1256179074495627264 

### Run:
Make sure you're goint to integrate all the files into a PlatformIO project structure. 

```c++
#define SSID "xxx" //WiFi SSID
#define PASSWORD "xxx" //WiFi Password

IPAddress g_MasterBedroomIP(000, 000, 0, 000); //Sonos Speaker IP
const char g_MasterBedroomID[] = "xxxxxxxxxxxxxx"; //Sonos Speaker ID
