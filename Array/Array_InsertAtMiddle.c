#include <stdio.h>

void display(int n, int arr[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertAtMiddle(int *n, int arr[], int pos, int num)
{
    for (int i = *n - 1; i >= pos; i--)
    {
        arr[i + 1] = arr[i];
    }
    arr[pos] = num;
    (*n)++;
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
    int num, position;
    printf("Enter the element to be inserted: ");
    scanf("%d", &num);
    printf("Enter the position to be inserted: ");
    scanf("%d", &position);
    if (position >= 0 && position <= n)
    {
        insertAtMiddle(&n, arr, position, num);
        display(n, arr);
    }
    else
    {
        printf("Invalid position\n");
    }

    return 0;
}
