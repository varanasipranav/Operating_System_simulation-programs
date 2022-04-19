#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int main()
{
	int m=100,s[50],n=1,j,k,ch,ef=0;
	printf("1) Insert a segment \n 2) Delete a Segment \n 3) Exit \n");
	while(1)
	{
		printf("enter your choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("enter size of segment:");
					scanf("%d",&s[n]);
					if(s[n]<=m)
					{
						m=m-s[n];
						n++;
						printf("Available memory is %d",m);
					}
					else
					{
						ef=m;
						printf("external fragmentation is %d",ef);
					}
					break;
			case 2: printf("enter the segment number for deletion:");
					scanf("%d",&j);
					m=m+s[j];
					if(j!=n-1)
					ef=ef+s[j];
					printf("external fragmentation %d \n",ef);
					s[j]=0;
					printf("Available memory is %d",m);
					break;
			case 3: exit(1);
			
			default: printf("enter a valid choice");		 
		}
		
	}
}


