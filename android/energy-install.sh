#!/bin/bash

# energy-install.sh
# Run on host
# Push binary and install it on /system/bin

NRG_NAME=energy-test
ADB=/opt/android-sdk/platform-tools/adb

if [[ -z $1 ]]
  then
  echo "Please specify the name of the binary to install on device"
  else
  $ADB push $1 /sdcard/$NRG_NAME
  $ADB shell "su -c '\
  mount -o remount,rw /system ; \
  cp /sdcard/energy-test /system/bin/$NRG_NAME ; \
  chmod 755 /system/bin/$NRG_NAME ; \
  mount -o remount,ro /system
  '"
fi
