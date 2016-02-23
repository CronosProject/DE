#include <stdlib.h>
#include <stdio.h>

#include "network/network.h"

int main(int argc, char *argv[])
{
	struct Interfaces *interfaces = getInterfaces();

	if(interfaces != NULL) {
		printf("%d interfaces availables\n", interfaces->count);
		int i;
		for(i = 0; i < interfaces->count; i++)
		{
			struct Interface *current_interface = interfaces->interface_array[i];
			printf("Interface N°%d : \n%s\t%s:%d\n",
				i+1, current_interface->name, current_interface->addr, current_interface->port);
		}
		clean(interfaces);
	}

	size_t rx_bytes, rx_bytes_2, tx_bytes, tx_bytes_2, speed;

	if(readStats(&rx_bytes, "eth0", RX_BYTES))
		printf("RX_BYTES = %lu B = %lf MiB\n", rx_bytes, (double)rx_bytes/UNITS_MiB);

	if(readStats(&tx_bytes, "eth0", TX_BYTES))
		printf("TX_BYTES = %lu B = %lf MiB\n", tx_bytes, (double)tx_bytes/UNITS_MiB);

	if(readStats(&speed, "eth0", SPEED))
		printf("SPEED = %lu Mbits/s\n\n", speed);

	while(1)
	{
		readStats(&rx_bytes, "eth0", RX_BYTES);
		readStats(&tx_bytes, "eth0", TX_BYTES);
		sleep(1);
		readStats(&rx_bytes_2, "eth0", RX_BYTES);
		readStats(&tx_bytes_2, "eth0", TX_BYTES);
		
		// Mesure de la bande passante
		size_t bandwidth_down = (rx_bytes_2 - rx_bytes);
		size_t bandwidth_up = (tx_bytes_2 - tx_bytes);
		
		printf("Traffic actuel bande passante :\n"
			"\ttéléchargement : %f KiB/s\n"
			"\tenvoi : %f KiB/s\n",
			((double) bandwidth_down / UNITS_KiB), ((double) bandwidth_up / UNITS_KiB));
	}

	return 0;
}