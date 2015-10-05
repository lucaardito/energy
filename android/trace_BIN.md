# Trace binary
## Generate binary
Read [instruction](./setup_toolchain.md) to generate the toolchain and create an executable

## Install binary on device
Use the [energy-install.sh](./energy-install.sh) script.

By default the script pushes the binary in `/system/bin/energy-test`

## Run tests
Use the [runAdbScript.sh](./runAdbScript.sh) script.

This script uses a *wakelock* in order to wake up the the CPU and keep it awake to complete the test. Without the wakelock the program stops the execution until the device is woken up. At the end, the strace trace is pulled.

## Notes
* The tests are actually performed running commands through **adb over wifi**. This implies a little overhead to power the wireless interface. Actually this is necessary because the device is not working properly with the USB cable.
* It is necessary to perform the same tests using longer *sleep()* in order to discover other possible power behavior.