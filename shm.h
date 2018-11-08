#ifndef __SHM_H__
#define __SHM_H__

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define PATHNAME "."
#define PROJ_ID 0x1111
#define MAX_SIZE 4096

int CreateShm(int size);
int DestoryShm(int shmid);
int GetShm(int size);
int CommShm(int size,int flags);
#endif //__SHM_H__
