#include <stdio.h>

// Linear search function
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i; // Return index if found
    }
    return -1; // Not found
}

int main() {
    int arr[100], n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter number to search: ");
    scanf("%d", &key);

    int result = linearSearch(arr, n, key);

    if (result == -1)
        printf("%d not found in the array.\n", key);
    else
        printf("%d found at position %d (index %d).\n", key, result + 1, result);

    return 0;
}
