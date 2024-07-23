// 1636. Sort Array by Increasing Frequency (EASY)
// https://leetcode.com/problems/sort-array-by-increasing-frequency/description/?envType=daily-question&envId=2024-07-23


class Solution {
public:

    static bool comp(const pair<int, int>& a, const pair<int, int>& b){
        if(a.second == b.second) return a.first > b.first;
        return a.second < b.second;
    }

    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;

        for(int i=0;i<n;i++) mp[nums[i]]++;

        vector<pair<int, int>> vec(mp.begin(), mp.end());
        sort(vec.begin(), vec.end(), comp);

        vector<int> result;
        for(auto it : vec){
            for(int i=0;i<it.second;i++) result.push_back(it.first);
        }

        return result;

    }
};
