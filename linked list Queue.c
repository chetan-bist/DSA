#include<stdio.h>
#include<stdlib.h>
#include"conio2.h"
struct Queue{
int data;
 struct Queue*next;
};
void insert(struct Queue**,struct Queue**,int );
void display(struct Queue*,struct Queue*);
int select();
int main()
{
    struct Queue*front,*rear;
    front=rear=NULL;
    int choice,value;
    do{
    choice=select();
    switch(choice)
    {
         case 1:
            {
              clrscr();
              printf("Enter push element\n");
              scanf("%d",&value);
              insert(&front,&rear,value);
              printf("Press a enter to go back:");
              getch();
              clrscr();
              break;
            }
         case 2:
            {
                 clrscr();
                 display(front,rear);
                 printf("Press a enter to go back:");
                 getch();
                 clrscr();
                 break;
            }
        /* case 3:
            {
                clrscr();
                display(ptos);
                printf("Press a enter to go back:");
                getch();
                clrscr();
                break;
            }*/
         case 4:
            break;
          default:
              {
                clrscr();
                printf("sir you select wrong choice try again\n");
                printf("Press a enter to go back:");
                getch();
                clrscr();
                break;
              }

    }
    }while(choice!=4);
    return 0;
}
int select()
{
    int choice;
    printf("======Application of Linked List Queue=======\n");
    printf("=========menu=======\n");
    printf(" 1)insert\n 2) display\n 3)removing\n 4)exit\n");
    printf("Enter a choice ->");
    scanf("%d",&choice);
    return choice;
}
void insert(struct Queue** pf,struct Queue**pr,int x)
{
    struct Queue*p;
    p=(struct Queue*)malloc(sizeof(struct Queue));

    if(p==NULL)
    {
        printf("Queue overflow");
        return;
    }
    p->data=x;
    p->next=NULL;
    if(*pf==NULL)
    {
        *pf=p;
    }
    else{
        (*pr)->next=p;
    }
    *pr=p;

}
void display(struct Queue*pf,struct Queue*pr)
{
    if(pf==NULL)
    {
        printf("Queue is empty");
        return;
    }
    do
    {
        printf("%d\n",pf->data);
        pf=pf->next;
    }while(pf!=NULL);
}
