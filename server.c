#include "shm.h"

int main()
{
	int shmid=CreateShm(MAX_SIZE);
	char* addr=(char*)shmat(shmid,NULL,0);
	sleep(3);
	int i=0;
	while(i++<26){
		printf("client# %s\n",addr);
		sleep(1);
	}
	shmdt(addr);
	sleep(2);
	DestoryShm(shmid);
	return 0;
}
