#ifndef H_TYPES_H
#define H_TYPES_H

// MACCROS
#define SHORT_INT 1
#define INT 2
#define LONG_INT 3
#define FLOAT 4
#define DOUBLE 5
#define LONG_DOUBLE 6
#define STRING 7
#define VOID_PTR 8

#define CPU 9
#define GPU 10
#define INTERFACES 11
#define SYSTEMINFO 12

/* Structures */

// CPU

struct Processor {
	char *vendor_id;
	char *model_name;

	unsigned int cores;
	unsigned short cpu_family;
};



// Memory

struct Ram {
  unsigned long size;
  unsigned long free;
  unsigned long used;
};
struct Swap {
  unsigned long size;
  unsigned long free;
  unsigned long used;
};
struct Processes {
  unsigned short count;
};

struct SystemInfo {
  long uptime;
  struct Ram ram;
  struct Swap swap;
  struct Processes processes;
};



// Network

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

#endif