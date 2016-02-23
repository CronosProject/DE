#include <stdlib.h>
#include <stdio.h>

#include <chronos.h>

int main(int argc, char* argv[])
{
	struct Processor *processor = get_cpu();
	struct SystemInfo *sysinfo = get_system_info();

  	printf("------------Cpu_Information------------\n"
		"Vendor id : %s\nModel name : %s\nCores : %d\nFamily : %d\n",
		processor->vendor_id, 
		processor->model_name, 
		processor->cores, 
		processor->cpu_family);

	printf("----------Disk_Information----------\n");
	    getDiskInfo();
  	printf("--------------RAM_INFO--------------\n"
	  	"ram size : %f GiB\nram used : %f GiB\nram free : %f GiB\n",
	  	(float)(sysinfo->ram.size / UNITS_GiB),
	  	(float)(sysinfo->ram.used / UNITS_GiB),
	  	(float)(sysinfo->ram.free / UNITS_GiB));

	printf("-------------Cpu_Usage--------------\n");
      struct Cpu *cpu1;
			getCpuUsage(cpu1);
			printf("Total Cpu Usage: %g%\n", cpu1->cpuUsage[0]);
			printf("cpu0: %g%\n", cpu1->cpuUsage[1]);
			printf("cpu1: %g%\n", cpu1->cpuUsage[2]);
			printf("cpu2: %g%\n", cpu1->cpuUsage[3]);
			printf("cpu3: %g%\n", cpu1->cpuUsage[4]);

	clean(processor, CPU);
	clean(sysinfo, SYSTEMINFO);

	return 0;
}
