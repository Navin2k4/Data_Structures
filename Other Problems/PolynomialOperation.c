#include <stdio.h>

void printPolynomial(int poly[], int n)
{
    int printed = 0; 
    for (int i = n - 1; i >= 0; i--){
        if (poly[i] != 0){
            if (printed)
                printf(" + ");
            if (i == 0)
                printf("%d", poly[i]);
            else if (i == 1)
                printf("%dx", poly[i]);
            else
                printf("%dx^%d", poly[i], i);
            printed = 1; 
        }
    }
    printf("\n");
}

void addPolynomials(int p1[], int n1, int poly2[], int n2)
{
    int maxSize = (n1 > n2) ? n1 : n2;
    int result[maxSize];
    for (int i = 0; i < maxSize; i++){
        int term1 = (i < n1) ? p1[i] : 0;
        int term2 = (i < n2) ? poly2[i] : 0;
        result[i] = term1 + term2;
    }

    printf("Sum: ");
    printPolynomial(result, maxSize);
}

void multiplyPolynomials(int p1[], int n1, int poly2[], int n2)
{
    int maxSize = n1 + n2 - 1;
    int result[maxSize];
    for (int i = 0; i < maxSize; i++){
        result[i] = 0;
    }
    for (int i = 0; i < n1; i++){
        for (int j = 0; j < n2; j++){
            result[i + j] += p1[i] * poly2[j];
        }
    }
    printf("Product: ");
    printPolynomial(result, maxSize);
}

int main()
{
    int n1, n2;
    printf("Enter the degree of Polynomial 1: ");
    scanf("%d", &n1);
    int p1[n1 + 1];
    printf("Enter the coefficients of Polynomial 1 from highest degree to constant term:\n");
    for (int i = n1; i >= 0; i--){
        scanf("%d", &p1[i]);
    }
    printf("Enter the degree of Polynomial 2: ");
    scanf("%d", &n2);
    int poly2[n2 + 1];
    printf("Enter the coefficients of Polynomial 2 from highest degree to constant term:\n");
    for (int i = n2; i >= 0; i--){
        scanf("%d", &poly2[i]);
    }
    printf("Polynomial 1: ");
    printPolynomial(p1, n1 + 1);
    printf("Polynomial 2: ");
    printPolynomial(poly2, n2 + 1);
    addPolynomials(p1, n1 + 1, poly2, n2 + 1);
    multiplyPolynomials(p1, n1 + 1, poly2, n2 + 1);
    return 0;
}
