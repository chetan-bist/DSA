#include<stdio.h>
#include<ctype.h>
    int chetan(char ch)
    {

        if(isalpha(ch)==0&&isdigit(ch)==0)
            return 0;
        return 1;
    }
int main()
{


    char num;
    printf("enter a digits\n");
    scanf("%c",num);

    if(chetan(num)==1)
        printf("sorry sir this not digit please try again\n");
      //if(isdigit(num)==1)
      else
            printf("your enter digit is =%d",num);
        return 0;
}
