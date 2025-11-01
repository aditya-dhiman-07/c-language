#include <stdio.h>
#include <math.h>

int main()
{
    double p, i, tc, t;
    double total;
    printf("Compound Intrest Calculator !!\n");
    printf("Enter the amount :\n");
    scanf("%lf", &p);
    printf("Enter the intrest per annum :\n");
    scanf("%lf", &i);
    i = i / 100;
    printf("Enter times compounded in a year :\n");
    scanf("%lf", &tc);
    printf("Enter the time in year :\n");
    scanf("%lf", &t);

    total = p * pow(1 + i / tc, t);
    printf("After %.0lf years amount will be $ %.2lf", t, total);
    return 0;
}