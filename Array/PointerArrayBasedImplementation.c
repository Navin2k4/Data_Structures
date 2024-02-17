#include <stdio.h>
#include <conio.h>

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void InsertAtFirst(int arr[], int n, int x)
{
    for (int i = n; i > 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = x;
    display(arr, n + 1);
}

void InsertAtMiddle(int arr[], int pos, int n, int num)
{
    for (int i = n; i > pos; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[pos] = num;
    display(arr, n + 1);
}

void InsertAtLast(int arr[], int num, int n)
{
    arr[n] = num;
    n = n + 1;
    display(arr, n);
}

int main()
{
    int n, num, position, choice;
    int arr[20];

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    printf("Enter the Array Elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int *ptr_arr = arr; // Pointer to the original array

    do
    {
        printf("\n1. Insert at First\n2. Insert at Middle\n3. Insert at Last\n0. Quit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the element to be inserted: ");
            scanf("%d", &num);
            InsertAtFirst(ptr_arr, n, num);
            break;

        case 2:
            printf("\nEnter the element to be inserted: ");
            scanf("%d", &num);
            printf("Enter the position to be inserted: ");
            scanf("%d", &position);
            if (position >= 0 && position <= n)
            {
                InsertAtMiddle(ptr_arr, position, n, num);
            }
            else
            {
                printf("Invalid position\n");
            }
            break;

        case 3:
            printf("\nEnter the element to be inserted: ");
            scanf("%d", &num);
            InsertAtLast(ptr_arr, num, n);
            break;

        case 0:
            printf("\nExiting the program.\n");
            break;

        default:
            printf("\nInvalid Choice\n");
        }
    } while (choice != 0);

    return 0;
}
