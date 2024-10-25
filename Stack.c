//program to demonstrate a menu
#include<stdio.h>
#include<stdlib.h>
#define mex 5
struct stack //define stack
{
    int arr[mex];
    int tos;
};
void push(struct stack*,int);
int pop(struct stack*);
void display(struct stack);
int main()
{
   struct stack s;
    int choice,num,result;
    char continu;
    s.tos=-1;
    do
    {
    system("cls");//clear the screen
    printf("this is menu-driven program\n");
    printf("menu:\n");
    printf("\n press 1)push\n press 2)pop\n press 3)display\n press 4)exit\n");
    printf("please enter your choice:\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        {
            printf("Enter push element\n");
            scanf("%d",&num);
            push(&s,num);
            break;
        }
    case 2:
       {
            result=pop(&s);
            if(result!=0)
            printf("popped element is=%d\n",result);
          break;
       }
    case 3:
        {
            display(s);
            break;
        }
    case 4:
        {
            printf("you selected to exit the program\n");
            return 0;

        }
    default:
        {
        printf("you selected to wrong choice please try again sir");
        break;
        }
    }
    printf("\n do you want to continue(y/n)\n");
    fflush(stdin);
    scanf("%c",&continu);
    }while(continu=='y');
    return 0;

}
void push(struct stack *p,int x)
{
    if(p->tos==mex-1)
    {
        printf("stack is overflow\n");
        return;
    }
    p->arr[++p->tos]=x;
}
int pop(struct stack *p)
{
    if(p->tos==-1)
    {
        printf("stack is underflow\n");
        return 0;
    }
    return p->arr[p->tos--];
}
void display(struct stack p)
{
    if(p.tos==-1)
    {
        printf("stack is empty\n");
        return;
    }
    int i=p.tos;
    while(i!=-1)
    {
        printf("%d\n",p.arr[i]);
        i--;
    }
}
