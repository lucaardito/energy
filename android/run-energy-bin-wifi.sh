#!/bin/bash

# run-energy-bin-wifi.sh
# Run on host
# The script pushes the right script to run a binary

#ADB=/opt/android-sdk/platform-tools/adb
ADB=adb
SCRIPT_PATH="scripts_device/"
SCRIPT="run-bin-wifi-device.sh"

$ADB push $SCRIPT_PATH$SCRIPT /sdcard/
$ADB shell "su -c \"nohup sh /sdcard/$SCRIPT > /dev/null\""
