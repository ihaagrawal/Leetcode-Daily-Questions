// 1508. Range Sum of Sorted Subarray Sums (MEDIUM)
// https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/description/?envType=daily-question&envId=2024-08-04


class Solution {
public:

    int MOD = 1e9 + 7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> sub;
        sub.push_back(-1);
        for(int i=0;i<n;i++){
            int s = 0;
            for(int j=i;j<n;j++){
                s = (s + nums[j]) % MOD;
                sub.push_back(s);
            }
        }

        sort(sub.begin(), sub.end());
        int sum = 0;
        for(int i=left;i<=right;i++) sum = (sum + sub[i]) % MOD;

        return sum;        
    }
};
