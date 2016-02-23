#include <cpu.h>

#define SLEEP 5

struct Processor* get_cpu()
{
  FILE *file = fopen("/proc/cpuinfo", "r");

  struct Processor *cpu = malloc(sizeof(struct Processor));
  cpu->vendor_id = NULL;
  cpu->model_name = NULL;
  cpu->cores = 0;
  cpu->cpu_family = 0;

  char buffer[1024];

  if(file != NULL && cpu != NULL)
  {
    while(fgets(buffer, 1024, file) != NULL)
    {
      if(replace_if_match_str(buffer, &cpu->model_name, "model name"))
        cpu->cores++;
      replace_if_match_str(buffer, &cpu->vendor_id, "vendor_id");
      replace_if_match_int(buffer, (int *)&cpu->cpu_family, "cpu family");
    }
    fclose(file);
  }
  return cpu;
}

void getCpuUsage(struct Cpu *cpu)
{
    void getCpuInfo(int *total_jiffies, int *work_jiffies)
    {
        struct Processor *processor;
        processor = get_cpu();
        int cores = processor->cores + 1;
        clean(processor, CPU);

        int i = 0;
        char line[100];
        cpu->nCores = cores;

        int user[cpu->nCores];int nice[cpu->nCores];
        int sys[cpu->nCores];int idle[cpu->nCores];
        int iowait[cpu->nCores];int irq[cpu->nCores];
        int softirq[cpu->nCores];
        FILE *file = fopen("/proc/stat", "r");
            while(i != cores)
            {
              fgets(line, 100, file);
              cpu->info[i] = strdup(line);
              sscanf(cpu->info[i], "%s %d %d %d %d %d %d %d",&cpu->name[i],&user[i],&nice[i],&sys[i],&idle[i],&iowait[i],&irq[i],&softirq[i]);
              total_jiffies[i] = user[i]+nice[i]+sys[i]+idle[i]+iowait[i]+irq[i]+softirq[i];
              work_jiffies[i] = user[i]+nice[i]+sys[i];
              i++;
            }
        fclose(file);
      }
      int i, total_jiffies1[64], work_jiffies1[64], total_jiffies2[64], work_jiffies2[64];
      getCpuInfo(total_jiffies1, work_jiffies1);
      sleep(SLEEP);
      getCpuInfo(total_jiffies2, work_jiffies2);

      double work_over_period[cpu->nCores];double total_over_period[cpu->nCores];
      for(i = 0; i < cpu->nCores; i++)
      {
          work_over_period[i] = work_jiffies2[i] - work_jiffies1[i];
          total_over_period[i] = total_jiffies2[i] - total_jiffies1[i];
          cpu->cpuUsage[i] = work_over_period[i] / total_over_period[i] * 100;
      }

}
