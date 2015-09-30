# Instructions

## Device configuration
<table>
  <tr>
    <td>Device</td>
    <td><a href="https://en.wikipedia.org/wiki/Nexus_5">LG Nexus 5</a></td>
  </tr>
  <tr>
    <td>Android version</td>
    <td>Android 6.0 preview 3</td>
  </tr>
  <tr>
    <td>Recovery</td>
    <td><a href="https://twrp.me/devices/lgnexus5.html">TWRP 2.8.7.1</a></td>
  </tr>
  <tr>
    <td>Kernel</td>
    <td><a href="http://forum.xda-developers.com/google-nexus-5/development/rom-android-m-preview-2-flashable-zip-t3157299">StephanMC</a></td>
  </tr>
  <tr>
    <td>Root</td>
    <td><a href="https://download.chainfire.eu/740/SuperSU/BETA-SuperSU-v2.49.zip">SuperSU v2.49 beta</a></td>
  </tr>
</table>

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
