#include <mempool.h>

void clean(void *data, const short int data_type)
{
	if(data_type == CPU) {
		struct Processor *cpu = (struct Processor *) data;

		free(cpu->model_name);
		free(cpu->vendor_id);
		free(cpu);
	}
	else if(data_type == INTERFACES) {
		struct Interfaces *interfaces = (struct Interfaces *) data;
		int i;
		size_t count = interfaces->count;

		for(i = 0; i < count; i++)
		{
			struct Interface *interface = NULL;
			interface = interfaces->interface_array[i];
			if(interface != NULL)
				free(interface);
		}
		free(interfaces->interface_array);
		free(interfaces);
	}
	else if(data_type == SYSTEMINFO) {
		struct SystemInfo *sys = (struct SystemInfo *) data;

		free(sys);
	}
}