#include<stdio.h>
#define SIZE 5
int front=-1,rear=-1,ele,myCQ[SIZE];
void enqueue()
{
    printf("Enter the element:");
    scanf("%d",&ele);
    if((front==0 && rear==SIZE-1)||(front==rear+1))
        printf("Queue full");
    else
    {
        if(rear==SIZE-1 && front!=0)
        rear=-1;
        myCQ[++rear]=ele;
        printf("Enqueued successfully\n");
        if(front==-1)
            front=0;
    }
}
void dequeue()
{
    if(front==-1 && rear==-1)
        printf("Queue empty");
    else
    {
        ele=myCQ[front++];
        printf("Dequeued successfully\n");
        if(front-1==rear)
            front=rear=-1;
        if(front==SIZE)
            front=0;
    }
}
void display()
{
   if(front==-1)
        printf("Queue empty");
    else
    {
        int i;
        printf("The elements of the queue are:\n");
        if(front<=rear)
        {
           for(i=front;i<=rear;i++)
            printf("%d\t",myCQ[i]); 
        }
        else
        {
            for(i=0;i<=rear;i++)
              printf("%d\t",myCQ[i]);
            for(int i=front;i<=SIZE-1;i++)
              printf("%d\t",myCQ[i]);
        }
    }    
}
void main()
{
    int choice;
    while(1)
    {
        printf("\nEnter 1 to insert\nEnter 2 to delete\nEnter 3 to display\nEnter 4 to exit\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        if(choice==1)
            enqueue();
        if(choice==2)
            dequeue();
        if(choice==3)
            display();
        if(choice==4)
            exit(0);
    }
}