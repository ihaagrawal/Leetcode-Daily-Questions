// 1509. Minimum Difference Between Largest and Smallest Value in Three Moves (MEDIUM)
// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/?envType=daily-question&envId=2024-07-03


class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size(), req = INT_MAX;
        if(n <= 3) return 0;

        sort(nums.begin(), nums.end());
        for(int i=1;i<=4;i++){
            req = min(req, abs(nums[n-i] - nums[4-i]));
        }
        return req;
    }
};
