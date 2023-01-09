//codeforce no:71A
//Problem name:Way to long words

#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,x;
    scanf("%d",&n);
    char word[n][102];
    for(i=0;i<n;i++)
    {
        scanf("%s",&word[i]);
        x=strlen(word[i]);
        if(10<x){
            printf("%c%d%c\n",word[i][0],x-2,word[i][x-1]);
        }
       else {
            printf("%s\n",word[i]);

        }
    }


    return 0;
}

