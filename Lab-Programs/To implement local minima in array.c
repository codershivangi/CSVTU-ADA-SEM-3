#include <stdio.h>
void findLocalMinima(int arr[], int n) {

    if (n == 1) {
        printf("Local minima: %d\n", arr[0]);
        return;
    }
    if (n == 2) {
        if (arr[0] < arr[1]) {
            printf("Local minima: %d\n", arr[0]);
        }
        if (arr[1] < arr[0]) {
            printf("Local minima: %d\n", arr[1]);
        }
        return;
    }

    for (int i = 1; i < n - 1; i++) {
        if (arr[i] < arr[i - 1] && arr[i] < arr[i + 1]) {
            printf("Local minima: %d at index %d\n", arr[i], i);
        }
    }

    if (arr[0] < arr[1]) {
        printf("Local minima: %d at index 0\n", arr[0]);
    }

    if (arr[n - 1] < arr[n - 2]) {
        printf("Local minima: %d at index %d\n", arr[n - 1], n - 1);
    }
}

int main() {
    int arr[] = {10, 20, 10, 30, 40, 30, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    findLocalMinima(arr, n);
    
    return 0;
}
