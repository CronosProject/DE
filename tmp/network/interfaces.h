#ifndef H_INTERFACES_H
#define H_INTERFACES_H

#include <stdlib.h>

typedef struct Interface
{
	char name[100];
	char addr[100];
	unsigned short port;
} Interface;

typedef struct Interfaces
{
	struct Interface **interface_array;
	unsigned short count;
} Interfaces;

int addInterface(struct Interfaces *Interfaces, char *name, char *addr, unsigned short port, size_t size);
struct Interfaces* getInterfaces();
void clean(struct Interfaces *interfaces);

#endif