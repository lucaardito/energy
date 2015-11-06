#!/bin/bash

# run-energy-bin-nowifi.sh
# Run on host
# 

#ADB=/opt/android-sdk/platform-tools/adb
ADB=adb
SCRIPT="run-bin-wifi-device.sh"

$ADB push $SCRIPT /sdcard/
$ADB shell "su -c \"nohup sh /sdcard/$SCRIPT > /dev/null\""
