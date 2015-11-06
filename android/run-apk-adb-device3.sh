#!/bin/bash

# run-apk-adb.sh
# Run on device
# Trace system calls of a running application (APK)

BUSY='energy-test'

if [ -z $1 ]; then
  echo "Please specify the length for the busy-sleep"
  su -c 'echo energy-lock > /sys/power/wake_unlock' # Release wakelock before exit
  exit 1
fi

# Gmail
#PACKAGE="com.google.android.gm"
#PACKAGE_REGEXP="com\.google\.android\.gm$"
#ACTIVITY="ConversationListActivityGmail"
# EnergyWhite
#PACKAGE="it.bbqcode.energy.empty"
#PACKAGE_REGEXP="it\.bbqcode\.energy\.empty$"
#ACTIVITY="White"
# EnergyImage
PACKAGE="ib.bbqcode.energy.image" # Typo in the apk
PACKAGE_REGEXP="ib\.bbqcode\.energy\.image$" # Typo in the apk
ACTIVITY="ImageActivity"
# EnergyWebImage
#PACKAGE="it.bbqcode.energy.webimage"
#PACKAGE_REGEXP="it\.bbqcode\.energy\.webimage$"
#ACTIVITY="WebImageActivity"

for (( i=0; i<30; i++ ))
do
	sleep $1
	energy-busy $1
	sleep $1
	am start -n $PACKAGE"/"$PACKAGE"."$ACTIVITY &&
	sleep 15  # ATM we are performing only a sleep
	am force-stop $PACKAGE
	am force-stop $PACKAGE  # Stopping again, just to be sure the application is completely closed
done
sleep $1
busy $1
