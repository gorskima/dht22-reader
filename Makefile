CC=~/c/rpi/tools/arm-bcm2708/arm-bcm2708hardfp-linux-gnueabi/bin/arm-bcm2708hardfp-linux-gnueabi-gcc

all:
	${CC} --std=gnu99 *.c -lrt -o dht22
