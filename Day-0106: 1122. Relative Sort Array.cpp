// 1122. Relative Sort Array (EASY)
// https://leetcode.com/problems/relative-sort-array/?envType=daily-question&envId=2024-06-11

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(), m = arr2.size();
        int ind = 0;

        map<int, int> mp;
        for(int i=0;i<n;i++) mp[arr1[i]]++;

        vector<int> result;
        for(int num : arr2){
            if(mp.find(num) != mp.end()){
                while(mp[num] > 0){
                    result.push_back(num);
                    mp[num]--;
                }
            }
            mp.erase(num);
        }

        for(auto& [key, count] : mp){
            while(count > 0){
                result.push_back(key);
                count--;
            }
        }

        return result;
    }
};
