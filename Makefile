CC=~/c/rpi/tools/arm-bcm2708/arm-bcm2708hardfp-linux-gnueabi/bin/arm-bcm2708hardfp-linux-gnueabi-gcc

PROGRAM_NAME=dht22

all:
	${CC} --std=gnu99 -DPROGRAM_NAME=${PROGRAM_NAME} *.c -lrt -o dht22

.PHONY: clean
clean:
	rm ${PROGRAM_NAME}
