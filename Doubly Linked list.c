#include<stdio.h>
#include<stdlib.h>
#include"conio2.h"
struct doubly
{
    struct doubly*prev;
    int data;
    struct doubly*next;
};
void append(struct doubly**,int);
void display(struct doubly*);
int del_first(struct doubly**);
int del_second(struct doubly**);
int select();
int main()
{
    struct doubly*start=NULL;
    int choice,value;
    do
    {
        choice=select();
        switch(choice)
        {
        case 1:
            {
                clrscr();
                printf("Enter element\n");
                scanf("%d",&value);
                append(&start,value);
                printf("press enter to go back:");
                getch();
                clrscr();
                break;
            }
        case 2:
            {
                clrscr();
                display(start);
                printf("press enter to go back:");
                getch();
                clrscr();
                break;
            }
        case 3:
            {
                clrscr();
                value=del_first(&start);
                if(value!=-1)
                printf("Delete element is= %d\n",value);
                printf("press enter to go back");
                getch();
                clrscr();
                break;
            }
        case 4:
            {
                clrscr();
                value=del_second(&start);
                if(value!=-1)
                printf("Delete element is= %d\n",value);
                printf("press enter to go back");
                getch();
                clrscr();
                break;
            }
        case 5:
            {
                break;
            }
        default:
            {
                clrscr();
                printf("sir you press wrong choice try again:\n");
                printf("press enter to go back:");
                getch();
                clrscr();
                break;
            }
        }
    }while(choice!=5);

    return 0;
}
int select()
{
    int choice;
    printf("=====Application of doubly Linked list====\n");
    printf("====menu=====\n");
    printf(" 1)append \n 2)display \n 3)Delete first node \n 4)Delete second node \n 5)exit\n");
    printf("====Enter choice==\n");
    scanf("%d",&choice);
    return choice;
}

void append(struct doubly**ps,int value)
{
    struct doubly*p,*temp;
    p=(struct doubly*)malloc(sizeof(struct doubly));
    p->data=value;
    p->next=NULL;
    if(*ps==NULL)
    {
        p->prev=NULL;
        *ps=p;
        return;
    }
    temp=*ps;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=p;
    p->prev=temp;
}
void display(struct doubly*p)
{
    if(p==NULL)
    {
        printf("List is empty\n");
        return;
    }
    while(p!=NULL)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
}
int del_first(struct doubly**ps)
{
    struct doubly*temp;
    int value;
    if(*ps==NULL)
    {
        printf("List is empty:\n");
        return -1;
    }
    temp=*ps;
    value=temp->data;
    *ps=temp->next;
    if(*ps!=NULL)
    {
        (*ps)->prev=NULL;
    }
    free(temp);
    return value;
}
int del_second(struct doubly**ps)
{
    struct doubly*temp;
    int value;
    if(*ps==NULL)
    {
        printf("List is empty\n");
        return -1;
    }
    temp=*ps;

    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    if(temp->prev==NULL)
    {
        *ps=NULL;
        value=temp->data;
        free(temp);
        return value;

    }
    temp->prev->next=NULL;
    value=temp->data;
    free(temp);
    return value;
}
