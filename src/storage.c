#include <storage.h>

void getDiskInfo()
{
  void diskInfo(unsigned long *diskSize, unsigned long *diskFree, unsigned long *diskUsed)
  {
    char *directory = "/";
    struct statvfs diskInfo;

    if(!statvfs(directory, &diskInfo))
    {
      unsigned long blockSize, blocks, freeBlocks;

      blockSize = diskInfo.f_bsize;
      blocks = diskInfo.f_blocks;
      freeBlocks = diskInfo.f_bfree;
      /*
      Division entre 1073741824 parce-que
      1 Gigabyte = 1073741824 bytes
      */
      *diskSize = blocks * blockSize / 1073741824;
      *diskFree = freeBlocks * blockSize / 1073741824;
      *diskUsed = *diskSize - *diskFree;
    }
    else
    {
      printf("Error");
    }
  }

  unsigned long diskSize, diskFree, diskUsed;
  diskInfo(&diskSize, &diskFree, &diskUsed);

  printf("Disk size:  %lu GB\nDisk usage: %lu GB\nFree space: %lu GB\n", diskSize,diskUsed,diskFree);
}
