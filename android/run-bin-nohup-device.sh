#!/system/bin/sh

# energy-run-standalone
# Run on device
# Utility to run the energy-test after a sleep. In this way it is possible to run this script with
# `nohup` and collect data with less overhead (it is possible to close the shell and disable wifi)

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
svc wifi disable
sleep $SLEEP_LEN
$BIN_NAME 5
svc wifi enable
echo energy-lock > /sys/power/wake_unlock