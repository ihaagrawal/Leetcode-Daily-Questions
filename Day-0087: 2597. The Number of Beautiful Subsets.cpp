// 2597. The Number of Beautiful Subsets (MEDIUM)
// https://leetcode.com/problems/the-number-of-beautiful-subsets/description/?envType=daily-question&envId=2024-05-23

class Solution {
public:

    int result;
    int k;

    void dfs(vector<int>& nums, int ind, unordered_map<int,int>& mp){
        if(ind>=nums.size()){
            result++;
            return;
        }

        dfs(nums, ind+1, mp);

        if(!mp[nums[ind]-k] && !mp[nums[ind]+k]){
            mp[nums[ind]]++;
            dfs(nums, ind+1, mp);
            mp[nums[ind]]--;
        }
    }

    int beautifulSubsets(vector<int>& nums, int K) {
        result=0;
        k=K;
        unordered_map <int, int> mp;
        dfs(nums, 0, mp);
        return result-1;
    }
};
