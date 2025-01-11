// 1400. Construct K Palindrome Strings (MEDIUM)
// https://leetcode.com/problems/construct-k-palindrome-strings/description/?envType=daily-question&envId=2025-01-11


class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size()) return false; 
        
        vector<int> charCount(26, 0);
        for (char c : s) charCount[c - 'a']++;
        
        int oddCount = 0;
        for (int count : charCount) {
            if (count % 2 != 0) oddCount++;
        }
        
        return oddCount <= k; 
    }
};
