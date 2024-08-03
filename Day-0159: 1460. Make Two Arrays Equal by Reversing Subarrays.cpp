// 1460. Make Two Arrays Equal by Reversing Subarrays (EASY)
// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/description/?envType=daily-question&envId=2024-08-03


class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
       return is_permutation(arr.begin(), arr.end(), target.begin()); 
    }
};
