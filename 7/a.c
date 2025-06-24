#include <stdio.h>

// Binary search function
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == key)
            return mid;  // Found at index mid
        else if (arr[mid] < key)
            low = mid + 1;  // Search in right half
        else
            high = mid - 1; // Search in left half
    }

    return -1;  // Not found
}

// Main function
int main() {
    int arr[100], n, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements in **sorted order**:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter number to search: ");
    scanf("%d", &key);

    int result = binarySearch(arr, n, key);

    if (result == -1)
        printf("%d not found in the array.\n", key);
    else
        printf("%d found at position %d (index %d).\n", key, result + 1, result);

    return 0;
}
