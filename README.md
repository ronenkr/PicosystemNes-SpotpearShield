# PicoSystem_InfoNes a NES emulator for the Spotpear pico shield

To Build:

git clone <this_repo>

cd PicoSystem_InfoNes-SpotpearShield

mkdir build

cd build

export PICO_SDK_PATH = <PATH_TO_PICO_SDK>

cmake ..

make -j4

# Sound
Sound is PWM available on GPIO20