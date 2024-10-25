#include<stdio.h>
int main()
{
    int arr[5];
    int value,i,j,temp;
    printf("enter 5 element\n");
    for( i=0;i<5;i++)
    {
        scanf("%d",&value);
        arr[i]=value;
    }
    for( i=1;i<5;i++)
    {
         temp=arr[i];
         j=i-1;
        while(arr[j]>temp&&j>=0)
        {
            arr[j+1]=arr[i];
            j--;

        }
        arr[j+1]=temp;
     }
        for( i=0;i<5;i++)
        {
            printf("%d\n",arr[i]);
        }
    return 0;
}
