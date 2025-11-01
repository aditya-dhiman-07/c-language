#include <stdio.h>
 
int main(){
double num1 = 0.0 ;
double num2 = 0.0 ;
double output = 0.0;
char operator = '\0';

printf("Enter the first number: ");
scanf("%lf",&num1);
printf("Enter the second number: ");
scanf("%lf",&num2);
printf("Enter the operator: (+,-,*,/) ");
scanf(" %c",&operator);

switch (operator)
{
case '+':
    printf("%lf",num1+num2);
    break;
    case '*':
    printf("%lf",num1*num2);
    
    break;
    case '-':
    printf("%lf",num1-num2);
    
    break;
    case '/':
    printf("%lf",num1/num2);
    
    break;

default:
    printf("Enter a valid operator");
    break;
}
return 0;
}