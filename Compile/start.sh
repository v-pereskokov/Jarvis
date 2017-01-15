#!/bin/sh

APP=$1

cd examples/$APP
if [ -f build-uno/$APP.hex ]; then
  cd build-uno/
  /Applications/Arduino.app/Contents/Java/hardware/tools/avr/bin/avrdude -C/Applications/Arduino.app/Contents/Java/hardware/tools/avr/etc/avrdude.conf -v -patmega328p -carduino -P/dev/cu.usbmodem1421 -b115200 -D -Uflash:w:$APP.hex:i
else
  make -f Makefile && cd build-uno/
  /Applications/Arduino.app/Contents/Java/hardware/tools/avr/bin/avrdude -C/Applications/Arduino.app/Contents/Java/hardware/tools/avr/etc/avrdude.conf -v -patmega328p -carduino -P/dev/cu.usbmodem1421 -b115200 -D -Uflash:w:$APP.hex:i
fi
