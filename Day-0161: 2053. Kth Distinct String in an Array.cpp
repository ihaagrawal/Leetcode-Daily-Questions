// 2053. Kth Distinct String in an Array (EASY)
// https://leetcode.com/problems/kth-distinct-string-in-an-array/description/?envType=daily-question&envId=2024-08-05

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size(), count = 0;
        map<string, int> mp;

        for(string& str : arr) mp[str]++;
        for(string& str : arr) {
            if(mp[str] == 1) k--;
            if(k == 0) return str;
        }
    
        return "";
    }
};
