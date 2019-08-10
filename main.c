#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>

int main()
{
	pid_t pid1, pid2, pid3, pid4, pid5;
	printf("Parent of all: %d\n",getpid());
	pid1=fork();
	if (pid1==0)
	{
		printf("#2 Child with id: %d and its Parent id: %d \n", getpid(),getppid());
		pid2 = fork();
		if (pid2==0)
		{
			printf("#4 Child with id: %d and its Parent id: %d \n", getpid(),getppid());
		}
         }
	 if (pid1>0)
	 {
		pid3 = fork();
		if (pid3==0)
		{
			printf("#3 Child with id: %d and its Parent id: %d \n", getpid(),getppid());
			for(int i=0; i<10000; i++)// otherwise 5th and 6th starts earlier than 4th
			wait(NULL); 
			pid4=fork();
			if (pid4==0)
			{
				printf("#5 Child with id: %d and its Parent id: %d \n", getpid(),getppid());
			}
			if (pid4>0)
			{
				pid5=fork();
				if(pid5==0)
				{
					printf("#6 Child with id: %d and its Parent id: %d \n", getpid(),getppid());
				}
			}
		}
	}
	for(int i=0; i<10; i++) 
	wait(NULL);
}
