#include <stdio.h>
#include <stdlib.h> 

#define maxdegree 9 

typedef struct
{
    int coeff[10];
    int highpow;
} *polynomial;

void polyadd(const polynomial poly1, const polynomial poly2, polynomial polysum);
void zeropolynomial(polynomial poly);

void zeropolynomial(polynomial poly)
{
    int i;
    for (i = 0; i <= maxdegree; i++)
    {
        poly->coeff[i] = 0;
    }
    poly->highpow = 0;
}

void polyadd(const polynomial poly1, const polynomial poly2, polynomial polysum)
{
    int i;
    zeropolynomial(polysum);
    polysum->highpow = (poly1->highpow > poly2->highpow) ? poly1->highpow : poly2->highpow;
    for (i = polysum->highpow; i >= 0; i--)
    {
        polysum->coeff[i] = poly1->coeff[i] + poly2->coeff[i];
    }
}

int main()
{
    polynomial poly1 = (polynomial)malloc(sizeof(struct polynomial));   
    polynomial poly2 = (polynomial)malloc(sizeof(struct polynomial));   
    polynomial polysum = (polynomial)malloc(sizeof(struct polynomial)); 

    poly1->coeff[0] = 3;
    poly1->coeff[1] = 0;
    poly1->coeff[2] = -4;
    poly1->highpow = 2;

    poly2->coeff[0] = 5;
    poly2->coeff[1] = 2;
    poly2->coeff[2] = 1;
    poly2->highpow = 2;

    polyadd(poly1, poly2, polysum);

    printf("Resultant Polynomial: ");
    for (int i = polysum->highpow; i >= 0; i--)
    {
        printf("%d", polysum->coeff[i]);
        if (i != 0)
        {
            printf("x^%d + ", i);
        }
    }
    printf("\n");

    free(poly1);  
    free(poly2);   
    free(polysum); 

    return 0;
}
