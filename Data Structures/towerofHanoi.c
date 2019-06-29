#include<stdio.h>
int count=0;
void tower(int n,int source,int temp,int dest)
{
    if(n==1)
    {
        printf("Move disc 1 from %c to %c\n",source,dest);
        count ++;
        return;
    }
	tower(n-1,source,dest,temp);
   	printf("Move disc %d from %c to %c\n",n,source,dest);
    	count++;
    	tower(n-1,temp,source,dest);
}

void main()
{
    int n;
    printf("Enter the number of discs\n");
    scanf("%d",&n);
    tower(n,'A','B','C');
    printf("Total number of disc moves=%d\n",count);
}