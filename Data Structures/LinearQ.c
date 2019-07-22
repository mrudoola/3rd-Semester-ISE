#include<stdio.h>
#define SIZE 5
int front=-1,rear=-1,ele,myQ[SIZE];
void enqueue()
{
    printf("Enter the element:");
    scanf("%d",&ele);
    if(rear==SIZE-1)
        printf("Queue full");
    else
    {
        if(front==-1)
        front=0;
        myQ[++rear]=ele;
        printf("Enqueued successfully\n");
    }
}
void dequeue()
{
    if(front==-1||front>rear)
        printf("Queue empty");
    else
    {
        ele=myQ[front++];
        printf("Dequeued successfully\n");
        if(front==rear+1)
        {
            front=-1;
            rear=-1;
        }
    }
}
void display()
{
   if(front==-1||front>rear)
        printf("Queue empty");
    else
    {
        printf("The elements of the queue are:\n");
        for(int i=front;i<=rear;i++)
        printf("%d\t",myQ[i]);
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