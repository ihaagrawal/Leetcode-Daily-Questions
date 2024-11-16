// 3254. Find the Power of K-Size Subarrays I (MEDIUM)
// https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/description/?envType=daily-question&envId=2024-11-16

class Solution {
public:

    bool increasing(vector<int>& temp){
        int n = temp.size();
        for(int i=0;i<n-1;i++){
            if(temp[i] >= temp[i+1]) return false;
        }
        return true;
    }

    bool consecutive(vector<int>& temp){
        int n = temp.size();
        for(int i=0;i<n-1;i++){
            if(temp[i]+1 != temp[i+1]) return false;
        }
        return true;
    }

    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;

        for(int i=0;i<=n-k;i++){
            vector<int> temp;
            for(int j=i;j<i+k;j++) temp.push_back(nums[j]);

            if(!consecutive(temp) || !increasing(temp)){
                result.push_back(-1);
                continue;
            }

            int num = *max_element(temp.begin(), temp.end());
            result.push_back(num);
        }

        return result;
    }
};
