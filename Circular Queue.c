#include<stdio.h>
#include<stdlib.h>
#include"conio2.h"
struct CQueue
{
    int arr[5];
    int front,rear;
};
void insert(struct CQueue *,int);
int del(struct CQueue *);
void display(struct CQueue);
//int choice();
int main()
{
    struct CQueue Q;
    int x,choice;

    Q.front=Q.rear=-1;
    do{
       //num=choice();
        system("cls");//clear the screen
        printf("=========menu:=========");
        printf("\n press 1)insert\n press 2)delete\n press 3)display\n press 4)exit\n");
        printf(" please enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
           case 1:
            {
                clrscr();
               printf("Enter element:");
               scanf("%d",&x);
               insert(&Q,x);
               printf("press enter to back:");
               getch();
               clrscr();
               break;
            }
           case 2:
              {
                  clrscr();
                x=del(&Q);
                if(x!=0)
                {
                    clrscr();
                    printf("Delete element=%d\n",x);
                    printf("press enter go to back:");
                    getch();
                    clrscr();
                    break;
                }
                printf("press enter go to back:");
                getch();
                    break;
              }
           case 3:
            {
                clrscr();
                display(Q);
                printf("\n press enter to back:\n");
                getch();
                clrscr();
                break;
            }
           case 4:
               {
                   printf("You selected to exit the program\n");
                   break;
               }
           default :
                clrscr();
                printf(" sorry sir your wrong choice select try\n");
                printf("\n press enter to back:\n");
                getch();
                clrscr();

        }
    }while(choice!=4);
    return 0;
}
/*int choice()
{
    int num;
    printf("=========menu=========");
    printf("\n 1)insert\n 2)delete\n 3)display\n 4)exit\n");
     while(1)
     {
         printf("Please enter your choice:\n");
         scanf("%d",&num);
         if(isalpha(num)==)
         {
             printf("sorry sir your wrong choice select try\n");
         }
         else{
            break;
         }
     }
    return num;
}*/
void insert(struct CQueue *Q,int num)
{
   // if((Q->rear==4&&Q->front==0)||(Q->rear+1==Q->front))
    if((Q->rear+1)%5==Q->front)
    {
        printf("Queue overflow\n");
        return;
    }
    /*if(Q->rear==4)
    {
        Q->rear=0;
    }
    else
    {
       Q->rear=Q->rear+1;
    }*/
    Q->rear=(Q->rear+1)%5;
    Q->arr[Q->rear]=num;
    if(Q->front==-1)
        Q->front=0;
}
int del(struct CQueue *Q)
{
    int num;
    if(Q->front==-1)
    {
        printf("Queue underflow\n");
        return 0;
    }
    num=Q->arr[Q->front];
    if(Q->front==Q->rear)
    {
        Q->front=Q->rear=-1;
    }
    else if(Q->front==4)
    {
        Q->front=0;
    }
    else
        Q->front=Q->front+1;
    return num;
}
void display(struct CQueue Q)
{
    int i;
    if(Q.rear==-1)
    {
        printf("Queue Underflow!");
        return;
    }
    if(Q.front<=Q.rear)
    {
        for(i=Q.front;i<=Q.rear;i++)
        {
            printf("%d\n",Q.arr[i]);
        }
    }
   //else if((Q.front-1==Q.rear)||(Q.rear+1<Q.front))
    //else if(Q.rear<=Q.front)
   else
    {

       for(i=Q.front;i<5;i++)
        {
            printf("\n%d ",Q.arr[i]);
        }
        for(i=0;i<=Q.rear;i++)
        {
            printf("\n%d",Q.arr[i]);
        }
    }
  /*  else if(Q.rear+1<Q.front)
    {
       for(i=Q.front;i<=4;i++)
        {
            printf("\n%d displayed",Q.arr[i]);
        }
        for(i=0;i<=Q.rear;i++)
        {
            printf("\n%d displayed",Q.arr[i]);
        }
    }*/
}

