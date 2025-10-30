#include <stdio.h>
#include <string.h>
 
int main(){
    char item[50] = "";
    char currency = '$';
    float price = 0.0f;
    int quantity = 0;
    float total = 0.0f;

    printf("What items would you like?");
    fgets(item,sizeof(item),stdin);
    item[strlen(item) - 1 ] = '\0';
    printf("What is the price for each?");
    scanf("%f",&price);
    printf("How many would you like? :)");
    scanf("%d",&quantity);
    total = price*quantity;
    printf("You have bought %s*%d\n",item,quantity);
    printf("%c %.2f", currency, total);
return 0;
}