#include <stdio.h>
#include<ctype.h>
struct Stack
{
    char arr[20];
    int tos;
};
void push(struct Stack *,char);
char pop(struct Stack *);
int isoperand(char);
int prcd(char,char);
int isempty(struct Stack);
void convert(char [],char []);
int main()
{
    char infix[20],postfix[20];
    printf("Enter a valid infix exp:");
    scanf("%s",infix);
    convert(infix,postfix);
    printf("\nPostfix exp = %s",postfix);
    return 0;
}
void convert(char infix[20],char postfix[20])
{
    struct Stack S;
    S.tos=-1;
    int i,j=0;
    char ch;
    int ans;
    for(i=0;infix[i]!='\0';i++)
    {
        ch=infix[i];
        if(isoperand(ch)==1)
        {
            postfix[j]=ch;
            j++;
        }


        else if(ch==')')
        {
            while(S.arr[S.tos]!='(')
            {
                postfix[j]=pop(&S);
                j++;
            }
            S.tos=S.tos-1;
        }
        else if(S.arr[S.tos]=='(' || ch=='(')
        {
            push(&S,ch);
        }
        else
        {
            while(isempty(S)==0)
            {
                ans=prcd(ch,S.arr[S.tos]);
                if(ans==1)
                {
                    break;
                }
                postfix[j]=pop(&S);
                j++;
            }
            push(&S,ch);
        }
    }
    while(isempty(S)==0)
    {
        postfix[j]=pop(&S);
        j++;
    }
    postfix[j]='\0';
}
void push(struct Stack *p,char ch)
{

	p->tos=p->tos+1;
	p->arr[p->tos]=ch;
}
char pop(struct Stack *p)
{
   char ch;

	ch=p->arr[p->tos];
	p->tos=p->tos-1;
	return ch;

}
int prcd(char op1,char op2)
{

    if(op2=='$')
	return 0;
	else if(op1=='$')
	return 1;
	else if(op2=='/'||op2=='*'||op2=='%')
	return 0;
	else if(op1=='/'||op1=='*'||op1=='%')
	return 1;
	else if(op2=='+'||op2=='-')
	return 0;
	else
	return 1;

}
int isoperand(char ch)
{
    //if((ch>=65&&ch<=90)||(ch>=97&&ch<=122)||(ch>=48&&ch<=57))
	if(isalpha(ch)==0 && isdigit(ch)==0)
	{
	return 0;
	}
	  return 1;
}
int isempty(struct Stack S)
{
    if(S.tos==-1) return 1;
	else
	return 0;
	//return (s.tos==-1);
}

