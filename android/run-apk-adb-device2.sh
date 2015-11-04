#!/bin/bash

# run-apk-adb.sh
# Run on device
# Trace system calls of a running application (APK)

BUSY='energy-test'

if [ -z $1 ]; then
  echo "Please specify a name for the test"
  su -c 'echo energy-lock > /sys/power/wake_unlock' # Release wakelock before exit
  exit 1
fi

DIR=/sdcard/test/"$1"
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

su -c 'setenforce 0'
rm -rf "$DIR"
mkdir -p "$DIR"
#$BUSY 8
#sleep 8
am start -n $PACKAGE"/"$PACKAGE"."$ACTIVITY &&
PID=$(pgrep "$PACKAGE_REGEXP")
su -c "strace -p $PID -q -ff -tt -T -s 500 -o \"$DIR/strace\"" &  # Now we are recording the trace
sleep 15  # ATM we are performing only a sleep
am force-stop $PACKAGE
am force-stop $PACKAGE  # Stopping again, just to be sure the application is completely closed
su -c 'killall strace'  # strace must be closed
