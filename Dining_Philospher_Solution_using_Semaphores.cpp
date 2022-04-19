#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t room;
sem_t cst[5];

void eat(int);
void * phil(void *);
int main()
{
	int i,a[5];
	pthread_t tid[5];
	sem_init(&room,0,4);
	for(i=0;i<5;i++)
	{
		sem_init(&cst[i],0,1);
		
		for(i=1;i<5;i++)
		{
			a[i]=i;
			
			pthread_create(&tid[i],NULL,phil,(void *)&a[i]);
		}
		for(i=0;i<5;i++)
		pthread_join(tid[i],NULL);
		
	}
}
	void * phil(void * num)
	{
		int p=*(int*)num;
		
		sem_wait(&room);
		printf("\n Philospher %d has entered the room",p);
		sem_wait(&cst[p]);
		sem_wait(&cst[(p+1)%5]);
		
		eat(p);
		sleep(2);
		printf("\n philospher %d has finisherd eating",p);
		
		sem_post(&cst[(p+1)%5]);
		sem_post(&cst[p]);
		sem_post(&room);
	}
	
	void eat(int p)
	{
		printf("\n philoshper %d is eating",p);
	}



