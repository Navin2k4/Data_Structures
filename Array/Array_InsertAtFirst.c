#include <stdio.h>

void display(int n, int arr[]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertAtFirst(int *n, int arr[], int x) {
    for (int i = *n; i > 0; i--) {
        arr[i] = arr[i - 1];
    }
    arr[0] = x;
    (*n)++;
}

int main() {
    int n;
    int arr[20];
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);
    printf("Enter the Array Elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int num;
    printf("Enter the element to be inserted at first: ");
    scanf("%d", &num);
    insertAtFirst(&n, arr, num);
    display(n, arr);

    return 0;
}
