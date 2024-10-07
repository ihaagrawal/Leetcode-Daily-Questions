// 2696. Minimum String Length After Removing Substrings (EASY)
// https://leetcode.com/problems/minimum-string-length-after-removing-substrings/description/?envType=daily-question&envId=2024-10-07


class Solution {
public:
    int minLength(string s) {
        string result;

        for (char c : s) {
            if (!result.empty() && ((result.back() == 'A' && c == 'B') || (result.back() == 'C' && c == 'D'))) {
                result.pop_back();
            } else result.push_back(c);
        }

        return result.size();
    }
};
