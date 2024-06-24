// 995. Minimum Number of K Consecutive Bit Flips (HARD)
// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/description/?envType=daily-question&envId=2024-06-24


class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int result = 0, count = 0;
        for(int i=0;i<n;i++){
            if((nums[i] + count) % 2 == 0){
                if(i > n - k) return -1;
                else{
                    result++;
                    count++;
                    nums[i] = -1;
                }
            }
            if(i + 1 >= k) count -= (nums[i - k + 1] < 0);
        }
        return result;
    }
};
