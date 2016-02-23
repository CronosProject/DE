#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define RX_BYTES 1
#define TX_BYTES 2
#define SPEED 3

#define KiB 1024
#define MiB 1048576
#define GiB 1073741824
#define TiB pow(1024, 4)

/* Cette fonction prends un pointeur data vers lequel stocker le résultat, une chaine de charactères correspondant à l'interface et un entier TYPE indiquant quel type de mesure nous voulons faire

 RX_BYTES et TX_BYTES correspondent respectivement au nombre de bytes reçus et envoyés par l'ordinateur depuis que l'interface réseau est connecté
Il suffit donc de faire la soustraction entre deux instants T pour avoir un débit.

*/

extern int readStats(size_t *data, const char *interface, const int TYPE);

int readStats(size_t *data, const char *interface, const int TYPE)
{
	FILE *file = NULL;
	
	char path[100] = "/sys/class/net/";
	strcat(path, interface);
	
	switch(TYPE)
	{
		case RX_BYTES:
			strcat(path, "/statistics/rx_bytes");
			file = fopen(path, "r");
			break;

		case TX_BYTES:
			strcat(path, "/statistics/tx_bytes");
			file = fopen(path, "r");
			break;

		case SPEED:
			strcat(path, "/speed");
			file = fopen(path, "r");
			break;
	}

	if(file != NULL)
	{
		fscanf(file, "%lu", (long int *)data);

		fclose(file);

		return 1;
	}
	else {
		return 0;
	}
}

int main(int argc, char* argv[])
{
	size_t rx_bytes, rx_bytes_2, tx_bytes, tx_bytes_2, speed;

	if(readStats(&rx_bytes, "eth0", RX_BYTES))
		printf("RX_BYTES = %lu B = %lf MiB\n", rx_bytes, (double)rx_bytes/MiB);

	if(readStats(&tx_bytes, "eth0", TX_BYTES))
		printf("TX_BYTES = %lu B = %lf MiB\n", tx_bytes, (double)tx_bytes/MiB);

	if(readStats(&speed, "eth0", SPEED)) {
		printf("SPEED = %lu Mbits/s\n\n", speed);
	}

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
			((double) bandwidth_down / KiB), ((double) bandwidth_up / KiB));
	}
		
	return 0;
}
