#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
struct node*start=NULL,*temp=NULL,*ptr=NULL;
void insertBegin()
{
	temp=(struct node*)malloc(sizeof(struct node));
	printf("Enter the data:");
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
void insertEnd()
{
temp=(struct node*)malloc(sizeof(struct node));
printf("Enter the data:");
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

void insertAny()
{
int count=0,pos,i;
ptr=start;
while(ptr!=NULL)
{
count++;
ptr=ptr->link;
}
printf("Enter the position:");
scanf("%d",&pos);
if(pos==1)
{
insertBegin();
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
	insertEnd();
}
else
{
printf("invalid");
}
}

void deleteBegin()
{
ptr=start;
if(start==NULL)
printf("List is empty");
else
{
start=start->link;
free(ptr);
}
}
void deleteEnd()
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
void deleteAny()
{
	int count=0,pos,i;
	ptr=start;
	while(ptr!=NULL)
	{
		count++;
		ptr=ptr->link;
	}
	printf("Enter the position:");
	scanf("%d",&pos);
	if(pos==1)
	{
		deleteBegin();
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
		deleteEnd();
	}
	else
	{
		printf("Wrong choice");
	}
}
void display()
{
if(start==NULL)
printf("List is empty");
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
printf("\n1.Insert Begin\n2.Display\n3.Insert in the end\n4.Insert in any loaction\n5.Delete Begin\n6.Delete from the end\n7.Delete from any loation\n");
	printf("Enter the choice:");
	scanf("%d",&ch);
	switch(ch)
	{
case 1:insertBegin();
	break;
case 2:display();
break;
case 3:insertEnd();
break;
case 4:insertAny();
	break;
case 5:deleteBegin();
break;
case 6:deleteEnd();
break;
case 7:deleteAny();
	break;
default: exit(0); 
}
}
}
