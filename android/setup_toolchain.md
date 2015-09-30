# Setup

- Download Android NDK
- Extract NDK in `/opt/android-ndk`
- run `/opt/android-ndk/build/tools/make-standalone-toolchain.sh --toolchain=arm-linux-androideabi-4.8 --system=linux-x86_64 --install-dir=/opt/android-toolchain --ndk-dir=/opt/android-ndk`
- Compile with `/opt/toolchain/bin/arm-linux-androideabi-gcc -FPIE -pie`. PIE flag is mandatory from Android 4.1 (API 16).

source: https://developer.android.com/ndk/guides/standalone_toolchain.html
