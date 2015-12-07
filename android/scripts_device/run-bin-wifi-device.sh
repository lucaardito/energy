#!/system/bin/sh

# run-bin-nowifi-device.sh
# Run on device
# Utility to run the energy-test after a sleep

if ! [ $(id -u) = 0 ]; then
	echo "Please run this script as root. It is required to acquire a wakelock."
	exit 1
fi

if [ -z $1 ]; then
  SLEEP_LEN=15
fi

if [ -z $2 ]; then
  BIN_NAME="energy-test"
fi

echo energy-lock > /sys/power/wake_lock
sleep $SLEEP_LEN
$BIN_NAME 5
echo energy-lock > /sys/power/wake_unlock
