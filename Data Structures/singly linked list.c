#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node*start=NULL,*cur=NULL,*temp=NULL,*ptr=NULL;
void insertbeg()
{
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the data");
scanf("%d",&temp->data);
temp->link=NULL;
if(start==NULL)
start=temp;
else
{
	temp->link=start;
	start=temp;
}
}
void insertend()
{
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the data");
scanf("%d",&temp->data);
temp->link=NULL;
if(start==NULL)
start=temp;
else
{
ptr=start;
while(ptr->link!=NULL)
{
ptr=ptr->link;
}
ptr->link=temp;
}
}

void loc_based()
{
int count=0,pos,i;
ptr=start;
while(ptr!=NULL)
{
count++;
ptr=ptr->link;
}
printf("enter the position\n");
scanf("%d",&pos);
if(pos==1)
{
insertbeg();
}
else if(pos>1 && pos<=count)
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("enter the data\n");
	scanf("%d",&temp->data);
	temp->link=NULL;
	ptr=start;
	for(i=1;i<=pos-1;i++)
	{
		ptr=ptr->link;
	}
temp->link=ptr->link;
ptr->link=temp;
}
else if(pos=count+1)
{
insertend();
}
else
{
printf("invalid");
}
}

void deletebeg()
{
ptr=start;
if(start==NULL)
printf("empty");
else
{
start=start->link;
free(ptr);
}
}
void deleteend()
{
ptr=start;
while(ptr->link!=NULL)
{
temp=ptr;
ptr=ptr->link;
}
temp->link=NULL;
free(ptr);
}
void del_any()
{
	int count=0,pos,i;
	ptr=start;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->link;
	}
	printf("enter the pos\n");
	scanf("%d",&pos);
	if(pos==1)
	{
	deletebeg();
	}
	else if(pos>1 && pos<=count)
	{
		ptr=start;
		for(i=1;i<pos;i++)
		{
			temp=ptr;
			ptr=ptr->link;
		}
		temp->link=ptr->link;
	}
	else if(pos=count+1)
	{
		deleteend();
	}
	else
	{
	printf("wrong choice");
	}
}
void display()
{
if(start==NULL)
printf("list is empty");
else
{
ptr=start;
while(ptr!=NULL)
{
printf("%d\t",ptr->data);
ptr=ptr->link;
}
}
}
void main()
{
int ch;
while(1)
{
printf("1. insert in beg\n 2.display\n 3.insert in the end\n 4. insert anywhere\n 5.delete from the beg\n 6. delete from the end\n 7. delete from anywhere\n");
printf("enter the choice");
scanf("%d",&ch);
switch(ch)
{
case 1:insertbeg();
break;
case 2: display();
break;
case 3: insertend();
break;
case 4: loc_based();
break;
case 5: deletebeg();
break;
case 6: deleteend();
break;
case 7: del_any();
break;
default: exit(0); 
}
}
}
