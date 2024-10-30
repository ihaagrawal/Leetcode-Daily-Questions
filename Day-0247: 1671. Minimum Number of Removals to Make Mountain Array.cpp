// 1671. Minimum Number of Removals to Make Mountain Array (HARD)
// https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/?envType=daily-question&envId=2024-10-30


class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> lis(n, 1), lds(n, 1);

        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i] > nums[j]){
                    lis[i] = max(lis[i], lis[j]+1);
                }
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int j=i+1;j<n;j++){
                if(nums[i] > nums[j]){
                    lds[i] = max(lds[i], lds[j]+1);
                }
            }
        }

        int min_num = n;
        for(int i=0;i<n;i++){
            if(lis[i] > 1 && lds[i] > 1) min_num = min(min_num, n - lds[i] - lis[i] + 1);
        }

        return min_num;
    }
};
