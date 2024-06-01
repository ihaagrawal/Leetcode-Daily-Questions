// 238. Product of Array Except Self (MEDIUM)
// https://leetcode.com/problems/product-of-array-except-self/description/?envType=daily-question&envId=2024-03-15

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;

    int* answer = (int*)malloc(sizeof(int) * numsSize);

    int product = 1;
    for (int i = 0; i < numsSize; i++) {
        answer[i] = product;
        product *= nums[i];
    }

    product = 1;
    for (int i = numsSize - 1; i >= 0; i--) {
        answer[i] *= product;
        product *= nums[i];
    }

    return answer;
}
