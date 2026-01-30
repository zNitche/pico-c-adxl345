# pico-c-adxl345
PicoSDK (C) module for performing measurements using ADXL345 accelerometer 

#### Resources
- [Datasheet](https://www.sparkfun.com/datasheets/Sensors/Accelerometer/ADXL345.pdf)


#### Notes WIP

```
mkdir -p ~/SDKs/pico-sdk
cd ~/SDKs/pico-sdk
git clone -b "2.2.0" --single-branch https://github.com/raspberrypi/pico-sdk.git 2.2.0
```

```
cd ~/SDKs/pico-sdk/2.2.0
git submodule update --init
```

Open devcontainer

```
cmake -S . -B build

cd build
make -j 16
```

```
screen /dev/tty.1
CTRL + A & CTRL + \
```

```
sh copy_utf2.sh ./build/example.uf2 /Volumes/RPI-RP2
```

```
cmake -DDEBUG=1 -S . -B build
```

added `pico_bootsel_via_double_reset` -> double tap reset btn