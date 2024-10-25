#include<stdio.h>
#include"conio2.h"
#define size 5
void sel_sort(int arr[],int);
int menu();
int main()
{
    int arr[size];
    arr[0]=1000;
    int choice;
    do
    {
        choice=menu();
        switch(choice)
        {
        case 1:
            {
                clrscr();
                printf("enter the %d element\n",size);
                for(int i=0;i<size;i++)
                {
                    scanf("%d",&arr[i]);
                }
                printf("press a enter to go back:");
                getch();
                clrscr();
                break;
            }
        case 2:
            {
                clrscr();
                if(arr[0]!=1000)
                {
                sel_sort(arr,size);
                printf("sorted element\n");
                for(int i=0;i<size;i++)
                {
                  printf("%d\n",arr[i]);
                }
                printf("press a enter to go back:");
                getch();
                clrscr();
                }
                else{
                      clrscr();
                      printf("sorry sir array is empty try again\n ");
                      printf("press a enter to go back:");
                      getch();
                      clrscr();
                }
                break;

            }

        case 3:
            break;
        default:
            {
                clrscr();
                printf("sir you select wrong choice try again \n");
                printf("press a enter to go back:");
                getch();
                clrscr();
            }
        }
    }while(choice!=3);

}
int menu()
{
    int choice;
    printf("========Application of selection sort=====\n");
    printf("============menu===========\n");
    printf(" 1) insert element \n 2) selection sort \n 3) exit \n");
    printf("enter your choice\n");
    scanf("%d",&choice);
    return choice;
}
void sel_sort(int arr[],int n)
{
   int i,j,temp,min;
   for(i=0;i<n-1;i++)
   {
       min=i;
       for(j=i+1;j<n;j++)
       {
           if(arr[j]<arr[min])
           {
               min=j;
           }
       }
       if(i!=min)
       {
           temp=arr[min];
           arr[min]=arr[i];
           arr[i]=temp;
       }
   }
}
