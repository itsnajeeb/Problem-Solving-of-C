#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main() 
{

    int a, b;
    printf("Enter a two no\n");
    scanf("%d\n%d", &a, &b);
    char number[9][6]={"one","two","three","four","five","six","seven","eight","nine"};
    int i;
    for (i=a;i<=b;i++){
        if(i>=1 && i<=9)
        printf("%s\n",number[i-1]);
        else if(i>9){
            if(i%2==0)
                printf("even\n");
            else
                printf("odd\n");
        }
    }
    return 0;
}

