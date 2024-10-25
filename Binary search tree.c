#include<stdio.h>
#include<stdlib.h>
#include"conio2.h"
struct tree
{
   struct tree*left;
   int data;
   struct tree*right;
   int flag;
};
struct stack
{
    int tos;
    struct stack *arr[10];
};
void append(struct tree**,int);
void preorder(struct tree*);
void inorder(struct tree*);
void postorder(struct tree*);
void del_node(struct tree**,int);
int search(struct tree*,int,struct tree**,struct tree**);
void push(struct stack*,struct tree*);
struct tree* pop(struct stack*);
int menu();
int main()
{
    struct tree*root=NULL;
    int select,value;
    do
    {
        clrscr();
        select=menu();
        switch(select)
        {
        case 1:
            {
                clrscr();
                printf("Enter the data\n");
                scanf("%d",&value);
                append(&root,value);
                printf("press enter to go back:");
                getch();
                clrscr();
                break;
            }
        case 2:
            {
                clrscr();
                preorder(root);
                printf("press enter to go back:");
                getch();
                clrscr();
                break;
            }
        case 3:
            {
                clrscr();
                inorder(root);
                printf("press enter to go back:");
                getch();
                clrscr();
                break;
            }
        case 4:
            {
                clrscr();
                postorder(root);
                printf("press enter to go back:");
                getch();
                clrscr();
                break;
            }
        case 5:
            {
                clrscr();
                printf("Enter deleted element\n");
                scanf("%d",&value);
                del_node(&root,value);
                printf("press enter to go back:");
                getch();
                clrscr();
                break;
            }
        case 6:
            break;
        }
    }while(select!=6);

    return 0;
}
int menu()
{
    int choice;
    printf("Application of binary search tree\n");
    printf("=======menu========\n");
    printf(" 1)append\n 2)preorder\n 3)inorder\n 4)postorder\n 5)del_node\n 6)exit\n");
     printf("enter your choice\n");
    scanf("%d",&choice);
    return choice;

}
void append(struct tree**pr,int value)
{
   struct tree *p,*temp,*prev;
   p=(struct tree*)malloc(sizeof(struct tree));
   if(p==NULL)
   {
       printf("memory insufficient");
       return;
   }
   p->data=value;
   p->left=p->right=NULL;
   if(*pr==NULL)
   {
       *pr=p;
       return;
   }
   temp=*pr;
   while(temp!=NULL)
   {
       prev=temp;
        if(temp->data>value)
        {
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
   }
   if(prev->data>value)
   {
       prev->left=p;
   }
   else{
    prev->right=p;
   }
}
void preorder(struct tree *p)
{
    struct stack s;
    if(p==NULL)
    {
        printf("empty tree\n");
        return;
    }
    s.tos=-1;
    push(&s,p);
    while(s.tos!=-1)
    {
        p=pop(&s);
        while(p!=NULL)
        {
            printf("%d\n",p->data);
            if(p->right!=NULL)
            {
              push(&s,p->right);
            }
            p=p->left;
        }

    }


}
void push(struct stack*ps,struct tree *pt)
{
    if(ps->tos==9)
    {
        printf("stack is empty\n");
        return;
    }
    ps->arr[++ps->tos]=(struct stack*)pt;
}
struct tree* pop(struct stack*ps)
{
  if(ps->tos==-1)
  {
      printf("stack is empty\n");
      return (struct tree*)0;
  }

  return (struct tree*)ps->arr[ps->tos--];

}
void inorder(struct tree*p)
{
    struct stack s;
    if(p==NULL)
    {
        printf("empty tree\n");
        return;
    }
    s.tos=-1;
    push_node:
        while(p!=NULL)
        {
            push(&s,p);
            p=p->left;
        }
        p=pop(&s);
        while(p!=NULL)
        {
            printf("%d\n",p->data);
            if(p->right!=NULL)
            {
                p=p->right;
                goto push_node;
            }
            p=pop(&s);
        }
}
void postorder(struct tree*p)
{
    struct stack s;
    if(p==NULL)
    {
        printf("empty tree\n");
        return;
    }
    s.tos=-1;
    push_node:
        while(p!=NULL)
        {
            p->flag=1;
            push(&s,p);
            if(p->right!=NULL)
            {
                p->right->flag=-1;
                push(&s,p->right);
            }
            p=p->left;
        }
        p=pop(&s);
        while(p!=NULL)
        {
            if(p->flag==1)
            {
                printf("%d\n",p->data);
            }
            else{
                goto push_node;
            }
            p=pop(&s);
        }
}
int search(struct tree*root,int value,struct tree**p_parent,struct tree**p_child)
{
    struct tree *q=NULL;
    while(root!=NULL)
    {
        if(root->data==value)
        {
            *p_child=root;
            *p_parent=q;
            return 1;
        }
        q=root;
        if(root->data>value)
        {
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return 0;
}
void del_node(struct tree**pr,int value)
{
    struct tree *child,*parent,*q;
    int result;
    if(*pr==NULL)
    {
        printf("Empty tree\n");
        return;
    }
    result=search(*pr,value,&parent,&child);
    if(result==0)
    {
        printf("Node not found!\n");
        return;
    }
    if(child->left!=NULL&&child->right!=NULL)
    {
        q=child->right;
        parent=child;
        while(q->left!=NULL)
        {
            parent=q;
            q=q->left;
        }
        child->data=q->data;
        child=q;
    }
    if(child->left==NULL&&child->right==NULL)
    {
        if(parent==NULL)
        {
            *pr=NULL;
        }
        else if(parent->left==child)
        {
            parent->left=NULL;
        }
        else
        {
            parent->right=NULL;
        }
        free(child);
    }
    else if(child->left!=NULL&&child->right==NULL)
    {
        if(parent==NULL)
        {
            *pr=child->left;
        }
        else if(parent->left==child)
        {
            parent->left=child->left;
        }
        else
        {
            parent->right=child->left;
        }
        free(child);
    }
    else if(child->right!=NULL&&child->left==NULL)
    {
        if(parent==NULL)
        {
            *pr=child->right;
        }
        else if(parent->left==child)
        {
            parent->left=child->right;
        }
        else
        {
            parent->right=child->right;
        }
        free(child);
    }
}
