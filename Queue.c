#include<stdio.h>
struct Queue
{
    int arr[5];
    int front;
    int rear;
};
void insert(struct Queue *,int);
int del(struct Queue *);
int main()
{
    struct Queue Q;
    int x;
    int result;
    Q.front=0;
    Q.rear=-1;
      do
      {
           printf("\n1)insert\n2)delete\n3)Quite\n");
           scanf("%d",&result);
           if(result==1)
           {
                  printf("enter element \n");
                  scanf("%d",&x);
                  insert(&Q,x);
           }
           else if(result==2)
           {
                x=del(&Q);
              if(x!=0)
              {
                 printf("delete element=%d",x);
              }
            }
            else if(result>=4)
                printf("sir try again you are wrong choice select");
           }while(result!=3);
    return 0;
}
void insert(struct Queue *p,int num)
{
    if(p->rear==4)
    {
        printf("Queue overflow\n");
        return;
    }
    p->arr[++p->rear]=num;
}
int del(struct Queue *p)
{
    if(p->front>p->rear)
    {
        printf("Queue underflow\n");
        return 0;
    }
    return p->arr[p->front++];
}
