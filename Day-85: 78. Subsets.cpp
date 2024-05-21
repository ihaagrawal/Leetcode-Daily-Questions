// 78. Subsets (MEDIUM)
// https://leetcode.com/problems/subsets/description/?envType=daily-question&envId=2024-05-21

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result = {{}}; 
        for (int num : nums) {
            int size = result.size();
            for (int i = 0; i < size; i++) {
                vector<int> subset = result[i];
                subset.push_back(num);
                result.push_back(subset);
            }
        }
        return result;
    }
};
