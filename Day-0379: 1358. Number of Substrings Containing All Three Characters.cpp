// 1358. Number of Substrings Containing All Three Characters (MEDIUM)
// https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/?envType=daily-question&envId=2025-03-11

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> count(3, 0);
        int start = 0, result = 0;
        
        for (int end = 0; end < s.size(); ++end) {
            count[s[end] - 'a']++;
            
            while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
                result += s.size() - end;
                count[s[start] - 'a']--;
                start++;
            }
        }
        
        return result;
    }
};
