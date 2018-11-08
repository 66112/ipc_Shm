#include "shm.h"
int main()
{
	int shmid=GetShm(MAX_SIZE);  //打开共享内存，4096字节，4KB
	char* addr=(char*)shmat(shmid,NULL,0);  //挂接到共享内存（标识码，缺省为NULL,缺省为0) 返回共享内存首地址
	sleep(1);
	int i=0;
	while(i<26){
		addr[i]='A'+i;
		sleep(1);
		i++;
		addr[i]=0;
	}
	shmdt(addr);	//解挂（内存地址）
	sleep(2);
	return 0;
}
