#ifndef H_BANDWIDTH_H
#define H_BANDWIDTH

#define RX_BYTES 1
#define TX_BYTES 2
#define SPEED 3

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../utils/units.h"

extern int readStats(size_t *data, const char *interface, const int TYPE);

#endif