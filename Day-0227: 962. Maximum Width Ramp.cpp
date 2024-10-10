// 962. Maximum Width Ramp (MEDIUM)
// https://leetcode.com/problems/maximum-width-ramp/description/?envType=daily-question&envId=2024-10-10

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int max_width = 0;

        vector<pair<int, int>> vec;
        for (int i = 0; i < n; i++) {
            vec.push_back({nums[i], i});
        }

        sort(vec.begin(), vec.end());

        int min_index = vec[0].second;

        for (int i = 1; i < n; i++) {
            int current_index = vec[i].second;
            max_width = max(max_width, current_index - min_index);
            min_index = min(min_index, current_index);
        }

        return max_width;
    }
};
