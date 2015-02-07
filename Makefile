# For cross-compilation, set this to point to your arch-specific gcc binary
CC=gcc
PROGRAM_NAME=dht22

all:
	${CC} --std=gnu99 -DPROGRAM_NAME=${PROGRAM_NAME} *.c -lrt -o dht22

.PHONY: clean
clean:
	rm ${PROGRAM_NAME}
