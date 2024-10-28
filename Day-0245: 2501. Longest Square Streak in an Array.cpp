// 2501. Longest Square Streak in an Array (MEDIUM)
// https://leetcode.com/problems/longest-square-streak-in-an-array/description/?envType=daily-question&envId=2024-10-28


class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        map<long long, int> mp;
        for(int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        int longestStreak = 0;
        for(int i = 0; i < n; i++) {
            int count = 0;
            long long sq = nums[i];

            while(mp.find(sq) != mp.end()) {
                count++;
                sq = sq * sq;
            }

            longestStreak = max(longestStreak, count);
        }

        return (longestStreak <= 1) ? -1 : longestStreak;
    }
};
