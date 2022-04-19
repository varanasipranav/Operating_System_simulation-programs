#include<stdio.h>
#define MAX 50
int main()
{
	int page[MAX],i,n,f,ps,off,pno;
	int ch=0;
	printf("Enter no. of pages in memory");
	scanf("%d",&n);
	printf("enter page size \n");
	scanf("%d",&ps);
	printf("enter no.of frames \n");
	scanf("%d",&f);
	for(i=0;i<n;i++)
		page[i]=-1;
	printf("enter page table \n");
	printf("enter frame number as -1 if it is not present \n");
	printf("\n pageno \t frameno\n     \t     ");
	for(i=0;i<n;i++)
	{
		printf("\n %d \t\t",i);
		scanf("%d",&page[i]);
	}
	do{
		printf("\n enter the logical address i.e page no and pageoffset \n");
		scanf("%d \t %d",&pno,&off);
		if(page[pno]==-1)
		printf("frame not found");
		else 
		printf("\n physical address: %d \t %d ",page[pno],off);
		printf("do you want to continue 0 or -1");
		scanf("%d",&ch);
		
	}while(ch ==1);
	return 1;
}
