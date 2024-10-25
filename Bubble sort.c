#include<stdio.h>
#include"conio2.h"
#define size 5
void Bubble_sort(int arr[],int);
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
                Bubble_sort(arr,size);
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
                      printf("sorry sir array is empty try again \n");
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
    return 0;
}
int menu()
{
    int choice;
    printf("========Application of Bubble sort=====\n");
    printf("============menu===========\n");
    printf(" 1) insert element \n 2) Bubble sort \n 3) exit \n");
    printf("enter your choice\n");
    scanf("%d",&choice);
    return choice;
}
void Bubble_sort(int arr[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
