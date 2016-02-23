#ifndef H_INTERFACES_H
#define H_INTERFACES_H

#include <stdlib.h>

#include <utils/types.h>

extern int addInterface(struct Interfaces *Interfaces, char *name, char *addr, unsigned short port, size_t size);
extern struct Interfaces* getInterfaces();

#endif