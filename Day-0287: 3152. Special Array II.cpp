// 3152. Special Array II (MEDIUM)
// https://leetcode.com/problems/special-array-ii/description/?envType=daily-question&envId=2024-12-09


class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<bool> alternating(n, false);
        
        // Preprocess the parity alternation information
        for (int i = 1; i < n; ++i) {
            alternating[i] = (nums[i] % 2 != nums[i - 1] % 2);
        }
        
        // Create the prefix sum array
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i < n; ++i) {
            prefix[i + 1] = prefix[i] + alternating[i];
        }
        
        vector<bool> result;
        for (const auto& query : queries) {
            int start = query[0];
            int end = query[1];
            if (start == end) {
                result.push_back(true);
            } else {
                result.push_back((prefix[end + 1] - prefix[start + 1]) == (end - start));
            }
        }
        
        return result;
    }
};
