#include "shm.h"

int CreateShm(int size)
{
	return CommShm(size,IPC_CREAT | IPC_EXCL | 0666);  //若共享内存已存在，则错误；若不存在，则创建
}

int DestoryShm(int shmid)
{
	if(shmctl(shmid,IPC_RMID,NULL)<0){     //控制共享内存，（标识码，删除操作，缺省为空）
		perror("rmid");
		return -1;
	}
	return 0;
}

int GetShm(int size)
{
	return CommShm(size,IPC_CREAT);  //若共享内存不存在，则创建；若存在，则访问
}

int CommShm(int size,int flags)
{
	key_t _key=ftok(PATHNAME,PROJ_ID);  //生成名字_key
	if(_key<0){
		perror("ftok");
		return -1;
	}
	int shmid=shmget(_key,size,flags);  //打开共享内存（名字，大小，权限）
	if(shmid<0){
		perror("shmget");
		return -1;
	}
	return shmid;   //返回标识码
}




