// 930. Binary Subarrays With Sum (MEDIUM)
// https://leetcode.com/problems/binary-subarrays-with-sum/?envType=daily-question&envId=2024-03-14

int numSubarraysWithSum(int* nums, int numsSize, int goal) {
    int* map = (int*)malloc(sizeof(int)*(numsSize+1));
    memset(map, 0, sizeof(int)*(numsSize+1));
    map[0] = 1;
    int sum = 0;
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        sum += nums[i];
        if (sum - goal >= 0) {
            count += map[sum - goal];
        }
        map[sum]++;
    }

    free(map);
    return count;
}
