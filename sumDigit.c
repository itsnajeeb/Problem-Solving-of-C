#include <stdio.h>
#include <string.h>


int main() {
	
    int n,sum=0;
    scanf("%d", &n);
    while(n){
        sum+=n%10;
        n=n/10;
    }
    printf("%d",sum);
    return 0;
}