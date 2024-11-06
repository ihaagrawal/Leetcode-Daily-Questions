// 3011. Find if Array Can Be Sorted (MEDIUM)
// https://leetcode.com/problems/find-if-array-can-be-sorted/description/?envType=daily-question&envId=2024-11-06


class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int count = -1;
        int prev_max = -1, mini = INT_MAX, maxi = -1;

        for(auto it : nums){
            int bits = __builtin_popcount(it);
            if(count == - 1 || bits == count){
                count = bits;
                mini = min(mini, it);
                maxi = max(maxi, it);
            }else{
                if(prev_max > mini) return false;
                count = bits;
                prev_max = maxi;
                mini = it;
                maxi = it;
            }
        }

        if(prev_max > mini) return false;
        return true;
    }
};
