#ifndef H_CPU_H
#define H_CPU_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include <utils/types.h>
#include <utils/string.h>

struct Processor* get_cpu();
struct Cpu
{
    int nCores;
    char name[64];
    double cpuUsage[64];
    char *info[];
};
void getCpuUsage(struct Cpu *cpu);

#endif
