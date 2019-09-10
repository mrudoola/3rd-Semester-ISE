#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node*llink;
struct node*rlink;
};
struct node*temp=NULL,*start=NULL,*ptr=NULL;
void insert()
{
temp = (struct node*)malloc(sizeof(struct node));
printf("enter the data\n");
scanf("%d",&temp->data);
temp->rlink = NULL;
temp->llink = NULL;
if(start == NULL)
{
start = temp;
}
else
{
ptr = start;
if(temp->data < start->data)
{
temp->rlink = start;
start->llink = temp;
start = temp;
}
else
{
while(ptr->rlink != NULL && ptr->data < temp->data)
ptr = ptr->rlink;
if(ptr->rlink==NULL && ptr->data < temp->data)
{
ptr->rlink = temp;
temp->llink = ptr;
}
else
{
temp->llink = ptr->rlink;
temp->rlink = ptr;
ptr->llink->rlink = temp;
ptr->llink = temp;
}
}
}
}
void display()
{
ptr = start;
while(ptr!=NULL)
{
printf("%d-->",ptr->data);
ptr = ptr->rlink;
}
}
void main()
{
int ch;
while(1)
{
printf("\n 1. insert\n 2. display\n");
printf("enter the choice\n");
scanf("%d",&ch);
switch(ch)
{
case 1: insert();
break;
case 2: display();
break;
default :exit(0);
}
}
}
