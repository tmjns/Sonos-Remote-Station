# Sonos-Remote-Station
This is the source code of the Sonos-Remote-Station: https://twitter.com/tmjns92/status/1256179074495627264 

### How to start:
This project was built with the PlatformIO IDE. So, I recommend you to install the PlatformIO extension for Visual Studio Code before you start. Don't forget to edit these lines before uploading:

```c++
#define SSID "________" // Your SSID
#define PASSWORD "________" // Your Password

IPAddress g_MasterBedroomIP(192, 168, 8, 112); //Your Sonos Speaker IP
const char g_MasterBedroomID[] = "1CBBFW9E899ED"; //Your Sonos Speaker ID
```
