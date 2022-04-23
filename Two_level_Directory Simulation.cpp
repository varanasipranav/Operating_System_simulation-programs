#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct
{
	char dname[10],fname[10][10];
	int fcnt;
}dir[10];
int main()
{
	int i,ch,dcnt,k;
	char f[30],d[30];
	dcnt=0;
	printf("-----------------------------------------------------------------------------------------\n");
	printf("1)Create Directory\t2)Create File\t3)Delete File\t4)Search File\t5)Display Files\t6)Exit\n");
	printf("-----------------------------------------------------------------------------------------\n");
	while(1)
	{
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("Enter name of directory: ");
			scanf("%s",dir[dcnt].dname);
			dir[dcnt].fcnt=0;		
			dcnt++;
			printf("Directory created!\n");
			break;
			case 2: printf("Enter name of the directory: ");
			scanf("%s",d);
			for(i=0;i<dcnt;i++)
			if(strcmp(d,dir[i].dname)==0)
			{
				printf("Enter name of the file: ");
				scanf("%s",dir[i].fname[dir[i].fcnt]);
				dir[i].fcnt++;
				printf("File created!\n");
				break;
			}
			if(i==dcnt)
				printf("Directory %s not found!\n",d);
			break;
			case 3: printf("Enter name of the directory: ");
			scanf("%s",d);
			for(i=0;i<dcnt;i++)
			{
				if(strcmp(d,dir[i].dname)==0)
				{
					printf("Enter name of the file: ");
					scanf("%s",f);
					for(k=0;k<dir[i].fcnt;k++)
					{
						if(strcmp(f, dir[i].fname[k])==0)
						{	
							printf("File %s is deleted!\n",f);
							dir[i].fcnt--; 
							strcpy(dir[i].fname[k],dir[i].fname[dir[i].fcnt]);
							goto jmp;
						}
					}
					printf("File %s not found!\n",f);
					goto jmp;
				}
			}
			printf("Directory %s not found!\n",d);
			jmp : break;
			case 4: printf("Enter name of the directory: ");
			scanf("%s",d);
			for(i=0;i<dcnt;i++)
			{
				if(strcmp(d,dir[i].dname)==0)
				{
					printf("Enter the name of the file: ");
					scanf("%s",f);
					for(k=0;k<dir[i].fcnt;k++)
					{
						if(strcmp(f, dir[i].fname[k])==0)
						{
							printf("File %s is found!\n",f);
							goto jmp1;
						}
					}
					printf("File %s not found!\n",f);
					goto jmp1;
				}
			}
			printf("Directory %s not found!\n",d);
			jmp1: break;
			case 5: if(dcnt==0)
			printf("No Directories!\n");
			else
			{	
				printf("Directory\tFiles");
				for(i=0;i<dcnt;i++)
				{
					printf("\n%s\t",dir[i].dname);
					for(k=0;k<dir[i].fcnt;k++)
						printf("\t%s\t",dir[i].fname[k]);	
				}
				printf("\n");
			}
			break;
			default:printf("Invalid choice!\n");
			break;
			case 6: exit(0);
		}
	}
}
