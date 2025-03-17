// 2206. Divide Array Into Equal Pairs (EASY)
// https://leetcode.com/problems/divide-array-into-equal-pairs/description/?envType=daily-question&envId=2025-03-17

class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int size = nums.size(), n = size / 2;
        map<int, int> mp;
        
        for(int i=0;i<size;i++) mp[nums[i]]++;
        for(auto it : mp){
            if(it.second % 2 != 0) return false;
        }

        return true;
    }
};
