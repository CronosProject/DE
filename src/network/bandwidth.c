#include "../../includes/network/bandwidth.h"

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
	else
		return 0;
}