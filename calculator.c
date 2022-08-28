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
        switch (c) {
        //Addition
        case '+':
            printf("%.2lf + %.2lf = %.2lf\n", a1, a2, a1 + a2);
            break;
        //Subtraction
        case '-':
            printf("%.2lf - %.2lf = %.2lf\n", a1, a2, a1 - a2);
            break;
        }
         }
    return 0;
}