#include<stdio.h>
#include<stdlib.h>
#include"conio2.h"
struct stack{
    int data;
    struct stack*next;
};
void push(struct stack**,int);
int pop(struct stack**);
void display(struct stack*);
int select();
int main()
{
    struct stack*ptos=NULL;
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
              push(&ptos,value);
              printf("Press a enter to go back:");
              getch();
              clrscr();
              break;
            }
         case 2:
            {
                 clrscr();
                 value=pop(&ptos);
                 if(value!=-1)
                 printf("popped element is ->%d\n",value);
                 printf("Press a enter to go back:");
                 getch();
                 clrscr();
                 break;
            }
         case 3:
            {
                clrscr();
                display(ptos);
                printf("Press a enter to go back:");
                getch();
                clrscr();
                break;
            }
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
    printf("======Application of Linked List Stack=======\n");
    printf("=========menu=======\n");
    printf(" 1)push\n 2)pop\n 3)display\n 4)exit\n");
    printf("Enter a choice ->");
    scanf("%d",&choice);
    return choice;
}
void push(struct stack**ptos,int value)
{
    struct stack *p;
    p=(struct stack*)malloc(sizeof(struct stack));
    if(p==NULL)
    {
       printf("Stack Overflow");
       return;
    }
    p->data=value;
    p->next=*ptos;
     *ptos=p;

}
int pop(struct stack **ptos)
{
    int value;
    struct stack *temp;
    if(*ptos==NULL)
    {
        printf("Stack is underflow\n");
        return -1;
    }
    temp=*ptos;
    value=(*ptos)->data;
    *ptos=temp->next;
    free(temp);
    return value;
}
void display(struct stack *ptos)
{
    struct stack *temp;
    if(ptos==NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    temp=ptos;
    do
    {
        printf("%d\n",temp->data);
        temp=temp->next;
    }while(temp!=NULL);
}
