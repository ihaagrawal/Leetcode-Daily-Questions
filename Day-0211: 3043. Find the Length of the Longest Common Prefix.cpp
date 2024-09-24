// 3043. Find the Length of the Longest Common Prefix (MEDIUM)
// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix/description/?envType=daily-question&envId=2024-09-24

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string, int> mp;

        for(int num : arr1){
            string str = to_string(num);
            string prefix = "";

            for(char ch : str){
                prefix += ch;
                mp[prefix]++;
            }
        }

        int max_len = 0;

        for(int num : arr2){
            string str = to_string(num);
            string prefix = "";

            for(char ch : str){
                prefix += ch;
                if(mp.find(prefix) != mp.end()){
                    max_len = max(max_len, static_cast<int>(prefix.length()));
                }
            }
        }

        return max_len;
    }
};
