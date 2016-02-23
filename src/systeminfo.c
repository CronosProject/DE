#include <systeminfo.h>

struct SystemInfo* get_system_info()
{
  struct SystemInfo *infos = NULL;
  struct sysinfo sys;

  if(!sysinfo(&sys))
  {
    infos = malloc(sizeof(struct SystemInfo));
    if(infos != NULL)
    {
      infos->uptime = sys.uptime;

      infos->ram.size = sys.totalram;
      infos->ram.free = sys.freeram;
      infos->ram.used = infos->ram.size - infos->ram.free;

      infos->swap.size = sys.totalswap;
      infos->swap.free = sys.freeswap;
      infos->swap.used = infos->swap.size - infos->swap.free;

      infos->processes.count = sys.procs;
    }
  }

  return infos;
}
