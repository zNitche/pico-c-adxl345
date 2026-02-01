# pico-c-adxl345
PicoSDK (C) module for performing measurements using ADXL345 accelerometer

#### Usage
Example at [example.c](src/example.c)

#### Connect to device
```
screen /dev/tty1
```

to exit 
```
CTRL + A -> CTRL + \
```

#### Development setup (devcontainer)

1. get pico-sdk
```
mkdir -p ~/SDKs/pico-sdk
cd ~/SDKs/pico-sdk
git clone -b "2.2.0" --single-branch https://github.com/raspberrypi/pico-sdk.git 2.2.0
```

2. initialize dependencies
```
cd ~/SDKs/pico-sdk/2.2.0
git submodule update --init
```

3. open project in devcontainer
4. setup project

```
cmake -S . -B build
```

or for debug mode

```
cmake -DDEBUG=1 -S . -B build
```

5. build
```
cd build
make
```

#### Extra

auto copying of `.uf2` file to MCU.
```
sh copy_uf2.sh ./build/example.uf2 /Volumes/RPI-RP2
```

#### Resources
- [ADXL345 Datasheet](https://www.sparkfun.com/datasheets/Sensors/Accelerometer/ADXL345.pdf)
