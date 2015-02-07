#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>

#include "pi_dht_read.h"

static struct option long_opts[] = {
	{"temperature",	no_argument,	0,	't'},
	{"humidity",	no_argument,	0,	'u'},
	{"help",	no_argument,	0,	'h'}
};

static int print_temp;
static int print_hum;

void usage() {
	printf("Usage: ./dht22 [-h|--help] [-t|--temperature] [-u|--humidity]\n");
}

void parse_args(int argc, char *argv[]) {
	int opt;
	while ((opt = getopt_long(argc, argv, "tuh", long_opts, NULL)) != -1) {
		switch (opt) {
			case 't':
				print_temp = 1;
				continue;
			case 'u':
				print_hum = 1;
				continue;
			case 'h':
				usage();
				exit(EXIT_SUCCESS);
			case '?':
				exit(-1);
		}
	}

	if (print_temp && print_hum) {
		usage();
		exit(EXIT_FAILURE);
	}
}

int main(int argc, char *argv[]) {
	parse_args(argc, argv);

        float h, t;
	
        if (pi_dht_read(DHT22, 17, &h, &t)) {
                fprintf(stderr, "Failed to read from the sensor\n");
                return -1;
        }

	if (print_temp)
		printf("%f\n", t);
	else if (print_hum)
		printf("%f\n", h);
	else {
		printf("Temperature: %.1f *C\n", t);
		printf("Humidity: %.1f %\n", h);
	}

	return EXIT_SUCCESS;
}

