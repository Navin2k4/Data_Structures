#include <stdio.h>

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void InsertAtLast(int arr[], int x, int n)
{
    arr[n] = x;
    display(arr, n + 1);
}

int main()
{
    int n;
    int arr[20];
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    printf("Enter the Array Elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int num;
    printf("Enter the element to be inserted at last: ");
    scanf("%d", &num);
    InsertAtLast(arr, num, n);

    return 0;
}
