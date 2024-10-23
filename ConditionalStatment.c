#include <stdio.h>

int main() {
    int n;
    char *words[]={"one","two","three","four","five","six","seven","eight","nine","ten"};
    // Prompt the user to enter a number
    scanf("%d", &n);

        // Check if the number is between 1 and 9
        if(n>=1 && n<=9){
            printf("%s\n",words[n-1]);
        }
        else{
        // Display an error message for numbers greater than 9
        printf("Greater than 9\n");
        }

    return 0;
}
