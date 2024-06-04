// 409. Longest Palindrome (EASY)
// https://leetcode.com/problems/longest-palindrome/description/?envType=daily-question&envId=2024-06-04

class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();

        map<char,int> mp;
        for(auto ch : s){
            mp[ch]++;
        }

        int count = 0;
        for (auto it = mp.begin(); it != mp.end(); ) {
            if (it->second % 2 == 0) {
                count += it->second;
                it = mp.erase(it);  
            } else {
                ++it;
            }
        }

        for(auto it : mp){
            if(it.second > 1){
                count += (it.second) - 1;
                it.second = 1;
            }
        }

        if(!mp.empty()) count += 1;

        return count;

    }
};
