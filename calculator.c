#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    char c;
    double a1, a2;
    while (1) {
        printf("Enter an operator (+, -, *, /), if want to exit enter '!': ");
        scanf(" %c", &c);
        if (c == '!') //exit condition
            exit(0);
        printf("Enter two first and second operand: ");
        scanf("%lf %lf",&a1,&a2);
         }
    return 0;
}