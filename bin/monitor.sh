#!/usr/bin/env sh
set -e

# This is a little hack,
# If you call the command without an argument, it suggests one that is probably an ESP32
if [ -z "$1" ]
then
  echo "Usage:\n  $0 $(echo /dev/cu.usbserial-*)"
  exit 1;
fi

# Put your own chip and baud rate here
arduino-cli monitor -b esp32:esp32:esp32 -p "$1" -c baudrate=115200