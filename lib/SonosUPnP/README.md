I edited Antonmeyer's fork to make a better example sketch, it's still in the works.

This fork should be the port for esp8266 AND now the esp32 as well.

There are examples for esp32 devices such as the m5stack.

This library requires the [microXPath](https://github.com/tmittet/microxpath) Library.

See (http://www.joeybabcock.me/blog/projects/arduino-esp8266-based-sonos-browser-controller/) for more details.
# sonos
This library makes interfacing an Arduino with your Sonos system a breeze. The library supports both controlling and reading the state of your Sonos components.  Playing URIs, files, online radio stations, playlists, and line-in is supported as well as the most common commands like play, pause, skip, mute, volume and speaker grouping.  What sets this library apart from similar libraries written for the Arduino platform it its ability to read the state of most of the Sonos functions: getting current source, state, track number, track position, volume and more.  The library is relatively compact and has a small enough memory footprint to function on Arduino Uno and Duemilanove.
