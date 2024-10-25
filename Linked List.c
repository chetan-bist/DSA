#include<stdio.h>
#include<stdlib.h>
#include"conio2.h"
struct node
{
    int data;
    struct node* next;

};
void append (struct node **,int);
void display(struct node*);
int searchnode(struct node*,int);
void del_firstnode(struct node **);
void del_lastnode(struct node **);
void del_any(struct node **,int);
int main()
{
    struct node *start=NULL;
    int choice,num,result;
    do
    {
        system("cls");
        printf("=========menu=========");
        printf("\n 1)append\n 2)display\n 3)search node\n 4)delete first node\n 5)delete last node\n 6)deleted any node\n 7)quite\n");
        printf(" please enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
          case 1:
          {
            clrscr();
            printf("Enter element\n");
            scanf("%d",&num);
            append(&start,num);
            printf("press enter go to back:");
            getch();
            clrscr();
            break;
          }
          case 2:
          {
            clrscr();
            display(start);
            printf("press enter go to back:");
            getch();
            clrscr();
            break;
          }
          case 3:
          {
              clrscr();
              printf("enter search element\n");
              scanf("%d",&num);
              result=searchnode(start,num);
              if(result==0)
              {
               printf("list is empty\n");
              }
              else if(result==-1)
              {
                   printf("this element=%d is not inside a node\n",num);
              }
              else
              {
                printf("node number is =%d\n",result);
              }
             printf("press enter go to back:");
             getch();
             clrscr();
                break;
         }
         case 4:
         {
             clrscr();
             del_firstnode(&start);
             printf("press enter go to back:");
             getch();
             clrscr();
            break;
         }
         case 5:
         {
             clrscr();
            del_lastnode(&start);
             printf("press enter go to back:");
             getch();
             clrscr();
            break;
         }
         case 6:
         {
             clrscr();
            printf("Enter the element and this element inside any node that node is deleted\n");
            scanf("%d",&num);
            del_any(&start,num);
             printf("press enter go to back:");
             getch();
             clrscr();
            break;
         }
         case 7:
        {
             printf("you selected to exit the program \n");
             break;
        }
         default:
            {
                clrscr();
               printf("sorry sir you are wrong choice selected try again\n");
               printf("press enter go to back:");
               getch();
               clrscr();
             break;
            }
      }
    }while(choice!=7);
    return 0;
}
void append(struct node **ps,int x)
{
    struct node *p,*temp;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=x;
    p->next=NULL;
    if(*ps==NULL)
    {
        *ps=p;
        return;
    }
    temp=*ps;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=p;

}
void display(struct node *p)
{
    if(p==NULL)
    {
        printf("list is empty\n");
        return;
    }
    while(p!=NULL)
    {
        printf("\n display element=%d\n",p->data);
        p=p->next;
    }
}
int searchnode(struct node *p,int x)
{
    int pos=0;
    if(p==NULL)
    {
        return pos;

    }
    while(p!=NULL)
    {
        pos++;
        if(p->data==x)
        {
            return pos;
        }
        p=p->next;
    }
    return -1;
}
void del_firstnode(struct node **ps)
{
    struct node *temp;
    if(*ps==NULL)
    {
        printf("list empty\n");
        return;
    }
    if((*ps)->next==NULL)
    {
        free(ps);
        *ps=NULL;
        printf("first node is deleted\n");
        return;
    }
    temp=*ps;
    *ps=(*ps)->next;
    free(temp);
    printf("first node is deleted\n");
}
void del_lastnode(struct node **ps)
{
    struct node *temp,*prev;
    if(*ps==NULL)
    {
        printf("list is empty\n");
        return;
    }
    if((*ps)->next==NULL)
    {
        free(ps);
        *ps=NULL;
        printf("deleted is last node\n");
        return;
    }
    temp=*ps;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;
    }
    free(temp);
    prev->next=NULL;
    printf("deleted is last node \n");

}
void del_any(struct node **ps,int x)
{
    struct node *temp,*prev;
    if(*ps==NULL)
    {
        printf("list is empty\n");
        return;
    }
    temp=*ps;
    if((*ps)->data==x)
    {
        *ps=temp->next;
        free(temp);
        printf("deleted node\n");
        return;
    }
    while(temp!=NULL&&temp->data!=x)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp==NULL)
    {
        printf("This %d element is not inside a any node\n",x);
    }
    else
    {
        prev->next=temp->next;
        free(temp);
        printf("deleted node\n");
    }

}
