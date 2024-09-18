// 179. Largest Number (MEDIUM)
// https://leetcode.com/problems/largest-number/description/?envType=daily-question&envId=2024-09-18

class Solution {
public:

    static bool comp(int a, int b){
        string str1 = to_string(a), str2 = to_string(b);

        return ((str1 + str2) > (str2 + str1)) ? true : false;
    }

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), comp);
        if(nums[0] == 0) return "0";
        string result = "";

        for(int num : nums) result += to_string(num);
        return result;
    }
};
