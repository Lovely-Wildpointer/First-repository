/*************************************************************************
    > File Name: test1.c
    > Author: nzt
    > Mail: 0xc4fed6c7ccce@gmail.com 
    > Created Time: 2020年11月23日 星期一 14时33分03秒
 ************************************************************************/

#include"ch10.h"
int main(int argc,char**argv)
{
	int r1,r2;
	r1 = fork();
	if(r1<0||r2<0){
		perror("fork failed!\n");
		exit(-1);
	}else if(r1==0){
		printf("child 1 pid = %d , ppid = %d , r1 = %d , r2 = %d\n",getpid(),getppid(),r1,r2);
		exit(88);
	}else if(r1>0){
		r2 = fork();
		if(r2==0){
			printf("child 2 pid = %d , ppid = %d , r1 = %d , r2 = %d\n",getpid(),getppid(),r1,r2);
			exit(99);
		}
		else{
			int t1,t2,s1,s2;
			t1 = wait(&s1);
			t2 = wait(&s2);
			printf("parent t1 = %d , t2 = %d, s1 = %d , s2 = %d\n",t1,t2,WEXITSTATUS(s1),WEXITSTATUS(s2));
			printf("parent pid = %d , ppid = %d , r1 = %d , r2 = %d\n",getpid(),getppid(),r1,r2);
			exit(0);
		}
	}
		return 0; 
}

