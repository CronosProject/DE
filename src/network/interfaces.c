#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <ifaddrs.h>

#include <network/interfaces.h>

int addInterface(struct Interfaces *interfaces, char *name, char *addr, unsigned short port, size_t size)
{
	if(interfaces != NULL)
	{
		if(interfaces->interface_array == NULL || size == 1)
			interfaces->interface_array = malloc(sizeof(struct Interface *));
		else
		interfaces->interface_array = realloc(interfaces->interface_array, sizeof(struct Interface *) * size);

		if(interfaces->interface_array != NULL)
		{
			struct Interface *new_interface = malloc(sizeof(struct Interface));
			if(new_interface != NULL)
			{
				strcpy(new_interface->name, name);
				strcpy(new_interface->addr, addr);
				new_interface->port = port;
			}
			interfaces->interface_array[interfaces->count] = new_interface; // fix me
			interfaces->count++;

			return 1;
		}
	}
	return 0;
}

struct Interfaces* getInterfaces()
{
	// Variables
	struct Interfaces *interfaces = malloc(sizeof(struct Interfaces));
	interfaces->count = 0;

	struct ifaddrs *ifap, *ifa;
	struct sockaddr_in *sa;
	size_t current_size;
	//

	if(interfaces != NULL)
	{
		getifaddrs(&ifap);

		for(ifa = ifap, current_size = 1; ifa; ifa = ifa->ifa_next, current_size++)
		{
			if(ifa->ifa_addr->sa_family == AF_INET)
			{
				sa = (struct sockaddr_in *) ifa->ifa_addr;

				addInterface(interfaces, ifa->ifa_name, inet_ntoa(sa->sin_addr), sa->sin_port, current_size);
			}
		}
		freeifaddrs(ifap);
	}

	return interfaces;
}