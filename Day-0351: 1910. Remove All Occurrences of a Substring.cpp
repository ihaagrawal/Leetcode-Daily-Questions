// 1910. Remove All Occurrences of a Substring (MEDIUM)
// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/?envType=daily-question&envId=2025-02-11


class Solution {
public:
    string removeOccurrences(string s, string part) {
        size_t pos;
        while ((pos = s.find(part)) != string::npos) {
            s.erase(pos, part.length());
        }
        return s;
    }
};
