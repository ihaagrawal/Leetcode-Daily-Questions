// 3068. Find the Maximum Sum of Node Values (HARD)
// https://leetcode.com/problems/find-the-maximum-sum-of-node-values/description/?envType=daily-question&envId=2024-05-19

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();

        long long min_xor=LLONG_MAX, sum=0;
        int count=0;
        for(int i=0;i<n;i++){
            if((nums[i]^k) <= nums[i]){
                sum += nums[i];
            }else{
                sum += nums[i]^k;
                count++;
            }
            min_xor = min(min_xor, static_cast<long long>(abs(nums[i]-(nums[i]^k))));
        }

        if(count%2!=0) return sum-min_xor;
        return sum;
    }
};
