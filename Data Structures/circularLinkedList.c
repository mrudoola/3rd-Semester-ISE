#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node*link;
};
struct node*last=NULL,*ptr=NULL,*temp=NULL;
void insertbeg()
{
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the data\n");
scanf("%d",&temp->data);
temp->link=NULL;
if(last==NULL)
{
last = temp;
temp->link=temp;

}
else
{
temp->link=last->link;
last->link=temp;
}
}
void insertend()
{
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the data\n");
scanf("%d",&temp->data);
temp->link=NULL;
if(last==NULL)
{
last = temp;
temp->link=temp;
}
else
{
temp->link=last->link;
last->link=temp;
last = temp;
}
}
void insertany()
{
int count=0,pos,i;
ptr=last->link;
while(ptr!=last)
{
count++;
ptr=ptr->link;
}
count++;
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
ptr=last->link;
for(i=1;i<pos-1;i++)
{
ptr=ptr->link;
}
temp->link=ptr->link;
ptr->link=temp;
}
}
void delbeg()
{
if(last==NULL)
{
printf("empty");
}
else
{
ptr=last->link;
last->link=ptr->link;
free(ptr);
}
}
void delend()
{
if(last==NULL)
{
printf("empty");
}
else
{
ptr=last->link;
while(ptr!=last)
{
temp=ptr;
ptr=ptr->link;
}
temp->link = last->link;
last = temp;
free(ptr);
}
}
void delany()
{
int count=0,pos,i;
ptr=last->link;
while(ptr!=last)
{
count++;
ptr=ptr->link;
}
count++;
printf("enter the position\n");
scanf("%d",&pos);
if(pos==1)
{
delbeg();
}
else if(pos>1 && pos<=count)
{
ptr=last->link;
for(i=1;i<pos;i++)
{
temp=ptr;
ptr=ptr->link;
}
temp->link=ptr->link;
free(ptr);
}
}
void display()
{
if(last==NULL)
{
printf("empty");
}
else
{
ptr=last->link;
while(ptr!=last)
{
printf("%d",ptr->data);
ptr=ptr->link;
}
printf("%d",ptr->data);
}
}
void main()
{
int ch;
while(1)
{
printf("\n1. display\n 2. insert beg\n 3. insert end\n 4. delete beg\n 5. delete end\n 6. insert any\n 7. delte any\n");
printf("enter the choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: display();
break;
case 2: insertbeg();
break;
case 3: insertend();
break;
case 4:delbeg();
break;
case 5:delend();
break;
case 6:insertany();
break;
case 7:delany();
break;
default:exit(0);
}
}
}
