/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// Online C compiler to run C program online
#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int data;
    struct queue *next;
};

struct queue *front=NULL,*rear=NULL;

void Enqueue(int);
int Dequeue();
void Display();

int main()
{
    int ch,d;
    do
    {
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter element you want to enter:");
                scanf("%d",&d);
                Enqueue(d);
                break;
            case 2:
                d=Dequeue();
                printf("Deleted element is %d",d);
                break;
            case 3:
                Display();
                break;

        }
    }while(ch!=4);
}

void Enqueue(int p)
{
    struct queue *new;
    new=(struct queue*)malloc(sizeof(struct queue));
    if(new==NULL)
        printf("Overflow\n");
    else
    {
        new->data=p;
        new->next=NULL;
        if(rear==NULL)
        {
            rear=new;
            front=new;
        }
        else
        {
            rear->next=new;
            rear=rear->next;
        }
    }
}

int Dequeue()
{
    int p;
    struct queue *temp;
    if(front==NULL)
        printf("Underflow\n");
    else
    {
        p=front->data;
        temp=front;
        if(rear==front)
        {
            rear=NULL;
            front=NULL;
            free(temp);
        }
        else
        {
            front=front->next;
            free(temp);
        }
        return p;
    }
}

void Display()
{
    struct queue *temp;
    temp=front;
    while(temp!=NULL)
    {
        printf(" %d",temp->data);
        temp=temp->next;
    }
}