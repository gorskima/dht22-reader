#include <stdio.h>

#include "pi_dht_read.h"

int main() {
        float h, t;
	
        if (pi_dht_read(DHT22, 17, &h, &t)) {
                fprintf(stderr, "Failed to read from the sensor\n");
                return -1;
        }
        
        printf("h=%f, t=%f\n", h, t);
        return 0;
}
