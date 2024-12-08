#include <stdio.h>
int majorityElement(int nums[], int n) {
    int candidate = -1, count = 0;
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            candidate = nums[i];
        }
        count += (nums[i] == candidate) ? 1 : -1;
    }
    count = 0;
    for (int i = 0; i < n; i++) {
        if (nums[i] == candidate) {
            count++;
        }
    }
    if (count > n / 2) {
        return candidate;
    } else {
        return -1; 
    }
}

int main() {
    int nums[] = {3, 3, 4, 2, 4, 4, 2, 4, 4}; 
    int n = sizeof(nums) / sizeof(nums[0]);

    int result = majorityElement(nums, n);

    if (result != -1) {
        printf("The majority element is %d\n", result);
    } else {
        printf("No majority element\n");
    }

    return 0;
}
