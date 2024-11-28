#include <stdio.h>
#include <limits.h> 
int maxSubArraySum(int nums[], int n) {
    int max_sum = INT_MIN;   
    int current_sum = 0;     
    for (int i = 0; i < n; i++) {
        current_sum += nums[i];  
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
        
        if (current_sum < 0) {
            current_sum = 0;
        }
    }
    
    return max_sum;  
}

int main() {
    int nums[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(nums) / sizeof(nums[0]);  
    int result = maxSubArraySum(nums, n);
    printf("Maximum sum of subarray is: %d\n", result);
    
    return 0;
}
