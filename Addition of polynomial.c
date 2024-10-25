#include<stdio.h>
#include<stdlib.h>
#include"conio2.h"
struct poly
{
    int cofficients;
    int exponent;
    struct poly*next;
};
void append(struct poly**,int,int);
void add(struct poly*,struct poly*,struct poly**);
int select();
int go();
int main()
{
    struct poly*first,*sec;
    first=sec=NULL;
    int cofficent,exponent,choice,value;
    do
    {
        choice=select();
        switch(choice)
        {
        case 1:
            {
                clrscr();
                choice=go();
                switch(choice)
                {
                case 1:
                    {
                       clrscr();
                       printf("Enter cofficient and exponent \n");
                       scanf("%d%d",&cofficent,&exponent);
                       append(&first,cofficent,exponent);
                       printf("press enter to go back:");
                       getch();
                       clrscr();
                       break;
                    }
                case 2:
                    {
                       printf("Enter cofficient and exponent \n");
                       scanf("%d%d",&cofficent,&exponent);
                       append(&sec,cofficent,exponent);
                       printf("press enter to go back:");
                       getch();
                       clrscr();
                       break;

                    }
                }
                break;
            }
        case 2:
            {
                clrscr();
               // display(start);
                printf("press enter to go back:");
                getch();
                clrscr();
                break;
            }
        case 3:
            {
                clrscr();
                //value=del_first(&start);
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
               // value=del_second(&start);
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
    printf("=====Application of Additions of polynomial Linked list====\n");
    printf("====menu=====\n");
    printf(" 1)append \n 2)display \n 3)Delete first node \n 4)Delete second node \n 5)exit\n");
    printf("====Enter choice==\n");
    scanf("%d",&choice);
    return choice;
}
int go()
{
    int choice;
    printf("===select first or second polynomial=====\n");
    printf("====menu====\n");
    printf(" 1)first polynomial \n 2)second polynomial \n");
    scanf("%d",&choice);
    return choice;
}
void append(struct poly**ps,int cofficient,int exponent)
{

}
void add(struct poly*first,struct poly*second,struct poly**pth;)
{
    struct poly *p,*temp,*q;
    if(first==NULL&&second==NULL)
    {
        printf("Addition not possible");
        return;
    }
    while(first!=NULL)&&second!=NULL)
    {
        p=(struct poly*)malloc(sizeof(struct poly));
        p->next=NULL;
        if(*pth==NULL)
            {
                *pth=p;
            }
            else
            {
                temp->next=p;
            }
            temp=p;
            if(first->exponent<second->exponent)
            {
                temp->cofficients=first->cofficients;
                temp->exponent=first->exponent;
                first=first->next;
            }
            else if(second->exponent<first->exponent)
            {
                temp->cofficients=second->cofficients;
                temp->exponent=second->exponent;
                second=second->next;
            }
            else
            {
                temp->cofficients=first->cofficients+second->cofficients;
                temp->exponent=second->exponent;
                first=first->next;
                second=second->next;
            }
    }
    if(f!=NULL)
    {
        q=first;
    }
    else
    {
        q=second;
    }
    while(q!=NULL)
    {
        p=(struct poly*)malloc(sizeof(struct poly));
        p->cofficients=q->cofficients;
        p->exponent=q->exponent;
        p->next=NULL;
        if(*pth==NULL)
        {
            *pth=p;
        }
        else
        {
            temp->next=p;
        }
        temp=p;
        q=q->next;
    }
}
