// 41. First Missing Positive (HARD)
// https://leetcode.com/problems/first-missing-positive/description/?envType=daily-question&envId=2024-03-26

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        vector<int> count(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]<=0 || nums[i]>n) continue;
            count[nums[i]-1]++;
        }

        for(int i=0;i<n;i++){
            if(count[i]==0)
                return i+1;
        }

        return n+1;
    }
};
