#include<stdio.h>
#include<stdlib.h>
#include"conio2.h"
struct cnode
{
    int data;
    struct cnode*next;
};
void append(struct cnode**,int);
void display(struct cnode*);
void del_first(struct cnode**);
void del_last(struct cnode**);
void del_any(struct cnode**,int);
int select();
int main()
{
    struct cnode*start=NULL;
    int num,choice;
    do
    {
        choice=select();
        switch(choice)
        {
        case 1:
            {
                clrscr();
                printf("Enter the element\n");
                scanf("%d",&num);
                append(&start,num);
                printf("Press Enter to back");
                getch();
                clrscr();
                break;
            }
        case 2:
            {
                clrscr();
                display(start);
                printf("\nPress Enter to back");
                getch();
                clrscr();
                break;
            }
        case 3:
            {
                clrscr();
                del_first(&start);
                printf("\nPress Enter to back");
                getch();
                clrscr();
                break;
            }
        case 4:
            {
                clrscr();
                del_last(&start);
                printf("\nPress Enter to back");
                getch();
                clrscr();
                break;
            }
        case 5:
            {
                clrscr();
                printf("Enter the deleting element\n");
                scanf("%d",&num);
                del_any(&start,num);
                printf("\nPress Enter to back");
                getch();
                clrscr();
                break;
            }
        case 6:
            break;
        default:
            {
                clrscr();
                printf("wrong choice selected try again\n");
                printf("Press Enter to back");
                getch();
                clrscr();
                break;
            }
        }
        }while(choice!=6);

    return 0;
}
int select()
{
    int choice;
    printf("\n 1) append\n 2) display\n 3) del_first_node\n 4) del_last_node\n 5) del_any_node\n 6) Exit\n");
    printf("Enter the choice\n");
    scanf("%d",&choice);
    return choice;
}
void append(struct cnode**ps,int num)
{
    struct cnode*p,*temp;
    p=(struct cnode*)malloc(sizeof(struct cnode));
    p->data=num;
    if(*ps==NULL)
    {
        *ps=p;
        p->next=p;
        return;
    }
    temp=*ps;
    while(temp->next!=*ps)
    {
        temp=temp->next;
    }
    temp->next=p;
    p->next=*ps;
}
void display(struct cnode*p)
{
    struct cnode*temp;
    if(p==NULL)
    {
        printf("List is empty");
        return;
    }
    temp=p;
    do
    {
        printf("\n%d",temp->data);
        temp=temp->next;
    }while(temp!=p);
}
void del_first(struct cnode**ps)
{
    struct cnode*temp;
    if(*ps==NULL)
    {
        printf("List is empty");
        return;
    }
    if((*ps)->next==*ps)
    {
        free(*ps);
        *ps=NULL;
        return;
    }
    temp=*ps;
    while(temp->next!=*ps)
    {
        temp=temp->next;
    }
    *ps=(*ps)->next;
    free(temp->next);
    temp->next=*ps;
}
//using two pointer
/*void del_second(struct cnode**ps)
{
    struct cnode*temp,*prev;
    if(*ps==NULL)
    {
        printf("List is empty");
        return;
    }
    if((*ps)->next==*ps)
    {
        free(*ps);
        *ps=NULL;
    }
    temp=*ps;
    while(temp->next!=*ps)
    {
        pre=temp;
        temp=temp->next;
    }
    free(temp);
    prev->next=*ps;
}*/
//using one pointer
void del_last(struct cnode**ps)
{
    struct cnode*temp;
    if(*ps==NULL)
    {
        printf("List is empty");
        return;
    }
    if((*ps)->next==*ps)
    {
        free(*ps);
        *ps=NULL;
    }
    temp=*ps;
    while(temp->next->next!=*ps)
    {
        temp=temp->next;
    }
    free(temp->next);
    temp->next=*ps;
}
//using two pointer
/*void del_any(struct cnode **ps,int x)
{
    struct cnode *temp,*prev;
    if(*ps==NULL)
    {
        printf("list is empty\n");
        return;
    }
     temp=*ps;
    if((*ps)->data==x)
    {
        if((*ps)->next==*ps)
        {
          free(*ps);
         *ps=NULL;
          printf("deleted node\n");
          return;
        }
        while(temp->next!=*ps)
        {
            temp=temp->next;
        }
        *ps=(*ps)->next;
        free(temp->next);
        temp->next=*ps;
        return;
    }
    while(temp->next!=*ps&&temp->data!=x)
    {
        prev=temp;
        temp=temp->next;
    }
    if(temp->next==*ps&&temp->data==x)
    {
        prev->next=temp->next;
        free(temp);
        printf("deleted node\n");
    }
    else if(temp->data!=x)
    {
        printf("This %d element is not inside a any node\n",x);
    }
    else
    {
        prev->next=temp->next;
        free(temp);
        printf("deleted node\n");
    }
}*/
void del_any(struct cnode **ps,int x)
{
    struct cnode *temp;
    if(*ps==NULL)
    {
        printf("list is empty\n");
        return;
    }
     temp=*ps;
    if((*ps)->data==x)
    {
        if((*ps)->next==*ps)
        {
          free(*ps);
         *ps=NULL;
          printf("deleted node\n");
          return;
        }
        while(temp->next!=*ps)
        {
            temp=temp->next;
        }
        *ps=(*ps)->next;
        free(temp->next);
        temp->next=*ps;
        return;
    }
    while(temp->next->next!=*ps&&temp->next->data!=x)
    {
       // prev=temp;
        temp=temp->next;
    }
    if(temp->next->next==*ps&&temp->next->data==x)
    {
        //prev->next=temp->next;
        free(temp->next);
        temp->next=*ps;
        printf("deleted node\n");
    }
    else if(temp->next->data!=x)
    {
        printf("This %d element is not inside a any node\n",x);
    }
    else
    {
       // prev->next=temp->next;
        free(temp->next);
        temp->next=*ps;
        printf("deleted node\n");
    }
}
