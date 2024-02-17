#include <stdio.h>

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
}

void InsertAtFirst(int arr[], int n, int x)
{
    for (int i = n; i > 0; i--)
        arr[i] = arr[i - 1];
    
    arr[0] = x;
    display(arr, n + 1);
}

void InsertAtMiddle(int arr[], int pos, int n, int num)
{
    for (int i = n - 1; i >= pos; i--)
        arr[i + 1] = arr[i];
    
    arr[pos] = num;
    display(arr, n + 1);
}

void InsertAtLast(int arr[], int x, int n)
{
    arr[n] = x;
    display(arr, n + 1);
}

int main()
{
    int n, num, position, choice;
    int arr[20];

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    printf("Enter the Array Elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    

    do
    {
        printf("\n1. Insert at First\n2. Insert at Middle\n3. Insert at Last\n0. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &num);
            InsertAtFirst(arr, n, num);
            break;

        case 2:
            printf("Enter the element to be inserted: ");
            scanf("%d", &num);
            printf("Enter the position to be inserted: ");
            scanf("%d", &position);
            if (position >= 0 && position <= n)
                InsertAtMiddle(arr, position, n, num);
            else
                printf("Invalid position\n");
            break;

        case 3:
            printf("Enter the element to be inserted: ");
            scanf("%d", &num);
            InsertAtLast(arr, num, n);
            break;

        case 0:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid Choice\n");
        }
    } while (choice != 0);

    return 0;
}
