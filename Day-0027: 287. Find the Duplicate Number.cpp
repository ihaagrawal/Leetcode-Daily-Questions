// 287. Find the Duplicate Number (MEDIUM)
// https://leetcode.com/problems/find-the-duplicate-number/description/?envType=daily-question&envId=2024-03-24

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n,0);
        for(int i=0;i<n;i++){
            count[nums[i]]++;
        }

        for(int i=0;i<n;i++){
            if(count[i]>1)
                return i;
        }

        return 0;
    }
};
