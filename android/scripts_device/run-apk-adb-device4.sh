#!/bin/bash

# run-apk-adb-device3.sh
# Run on device
# Launch application (APK) from command line (without strace)
# This script is used to record current values without the strace overhead

BUSY='energy-test'

if [ -z $1 ]; then
  echo "Please specify the length for the busy-sleep"
  su -c 'echo energy-lock > /sys/power/wake_unlock' # Release wakelock before exit
  exit 1
fi

# Gmail
PACKAGE="com.google.android.gm"
PACKAGE_REGEXP="com\.google\.android\.gm$"
ACTIVITY="ConversationListActivityGmail"

i=0
while [ i -lt 30 ]
do
  #sleep $1
  #energy-busy $1
  sleep $1
  am start -n $PACKAGE"/"$PACKAGE"."$ACTIVITY &&
  sleep 8  # ATM we are performing only a sleep
  input tap 343 222
  sleep 5
  am force-stop $PACKAGE
  am force-stop $PACKAGE  # Stopping again, just to be sure the application is completely closed
  i=$(expr $i + 1)
done
sleep $1
energy-busy $1
