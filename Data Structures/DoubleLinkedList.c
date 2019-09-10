#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*llink;
struct node*rlink;
};
struct node*start=NULL,*ptr=NULL,*temp=NULL;
void insertbeg()
{
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the data\n");
scanf("%d",&temp->data);
temp->rlink=NULL;
temp->llink=NULL;
if(start==NULL)
start=temp;
else
{
start->llink=temp;
temp->rlink=start;
start=temp;
}
}
void insertend()
{
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the data\n");
scanf("%d",&temp->data);
temp->rlink=NULL;
temp->llink=NULL;
if(start==NULL)
start=temp;
else
{
ptr=start;
while(ptr->rlink!=NULL)
{
ptr=ptr->rlink;
}
ptr->rlink=temp;
temp->llink=ptr;
}
}
void insertany()
{
int count=0,pos,i;
ptr=start;
while(ptr!=NULL)
{
count++;
ptr=ptr->rlink;
}
printf("enter the position\n");
scanf("%d",&pos);
if(pos==1)
insertbeg();
else if(pos>1 && pos<=count)
{
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the data\n");
scanf("%d",&temp->data);
temp->rlink=NULL;
temp->llink=NULL;
ptr=start;
for(i=1;i<pos-1;i++)
{
ptr=ptr->rlink;
}
temp->rlink=ptr->rlink;
temp->llink=ptr;
ptr->rlink->llink=temp;
ptr->rlink=temp;
}
else if(pos==count+1)
{
insertend();
}
else
{
printf("invalid");
}
}
void delbeg()
{
ptr=start;
start=start->rlink;
free(ptr);
}
void delend()
{
ptr=start;
while(ptr->rlink!=NULL)
{
temp=ptr;
ptr=ptr->rlink;
}
temp->rlink=NULL;
free(ptr);
}
void delany()
{
int count=0,i,pos;
ptr=start;
while(ptr!=NULL)
{
count++;
ptr=ptr->rlink;
}
printf("enter the position\n");
scanf("%d",&pos);
if(pos==1)
delbeg();
else if(pos>1 && pos<=count)
{
ptr=start;
for(i=1;i<pos;i++)
{
temp=ptr;
ptr=ptr->rlink;
}
temp->rlink=ptr->rlink;
ptr->rlink->llink= temp;
free(ptr);
}
}
void display()
{
ptr=start;
while(ptr!=NULL)
{
printf("%d",ptr->data);
ptr=ptr->rlink;
}
}
void main()
{
int ch;
while(1)
{
printf("\n1. display\n 2. insert beg\n 3. insert end\n 4. insert any\n 5. delete beg\n 6. delete end\n 7. delte any\n");
printf("enter the choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: display();
break;
case 2: insertbeg();
break;
case 3:insertend();
break;
case 4:insertany();
break;
case 5:delbeg();
break;
case 6:delend();
break;
case 7:delany();
break;
default:exit(0);
}
}
}