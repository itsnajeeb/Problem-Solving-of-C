#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int a,b[1000],sum=0;
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
   scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        scanf("%d", &b[i]); 
        sum+=b[i];
    }
    printf("%d",sum);
    return 0;
}
