#include<stdio.h>
#include<stdlib.h>
#include"conio2.h"
struct node{
int data;
struct node*next;
};
void append(struct node**,int);
void display(struct node*);
int searchnode(struct node*,int);
int select();
int main()
{
    struct node*start=NULL;
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
                printf("Enter search element\n");
                scanf("%d",&num);
                int result=searchnode(start,num);
                printf("%d",result);
                printf("\nPress Enter to back");
                getch();
                clrscr();
                break;
            }
        case 4:
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
        }while(choice!=4);

    return 0;
}
int select()
{
    int choice;
    printf("\n 1) append\n 2) display\n 3) search element\n 4) Exit\n");
    printf("Enter the choice\n");
    scanf("%d",&choice);
    return choice;
}
void append(struct node**ps,int num)
{
    struct node*p,*temp;
    p=(struct node*)malloc(sizeof(struct node));
    p->data=num;
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
void display(struct node*p)
{
    if(p==NULL)
    {
        printf("List is empty");
        return;
    }
    while(p!=NULL)
    {
        printf("\n%d",p->data);
        p=p->next;
    }
}
int searchnode(struct node*p,int num)
{
    int pos=0;
    if(p==NULL)
    {
        return pos;
    }\
    while(p!=NULL)
    {
        pos++;
        if(p->data==num)
        {
            return pos;
        }
        p=p->next;
    }
    return -1;;
}
