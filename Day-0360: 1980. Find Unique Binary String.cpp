// 1980. Find Unique Binary String (MEDIUM)
// https://leetcode.com/problems/find-unique-binary-string/description/?envType=daily-question&envId=2025-02-20


class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        string result = "";
        for (int i = 0; i < n; ++i) {
            result += (nums[i][i] == '0') ? '1' : '0';
        }
        return result;
    }
};
