// 2342. Max Sum of a Pair With Equal Sum of Digits (MEDIUM)
// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/?envType=daily-question&envId=2025-02-12


class Solution {
public:

    int sum(int num){
        int s = 0;
        while(num > 0){
            s += num % 10;
            num /= 10;
        }
        return s;
    }

    int findMax(vector<int> &arr){
        int s = -1;
        sort(arr.rbegin(), arr.rend()); 
        if (arr.size() >= 2) {
            s = arr[0] + arr[1]; 
        }
        return s;
    }

    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        for(int i=0; i<n; i++){
            int count = sum(nums[i]);
            mp[count].push_back(nums[i]);
        }

        int max_sum = -1;
        for(auto it : mp){
            if(it.second.size() > 1){
                max_sum = max(max_sum, findMax(it.second));
            }
        }

        return max_sum;
    }
};
