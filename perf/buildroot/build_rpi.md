*Download a snapshot
wget http://buildroot.uclibc.org/downloads/snapshots/buildroot-20150505.tar.bz2
The daily snapshot is http://buildroot.uclibc.org/downloads/snapshots/buildroot-snapshot.tar.bz2

*Extract
tar -xvf buildroot-20150505.tar.bz2

*Import default configuration
cd buildroot
make defconfig BR2_DEFCONFIG=configs/raspberrypi2_defconfig

*Tweak parameters
make nconfig

*Add lttng
http://lttng.org/docs/#doc-buildroot

*Compile the system
make BR2_JLEVEL=4

*Buildroot output is stored in a single directory, output/

*https://github.com/gamaral/rpi-buildroot
