// 2981. Find Longest Special Substring That Occurs Thrice I (MEDIUM)
// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-i/description/?envType=daily-question&envId=2024-12-10


class Solution {
public:
    bool isSpecial(string str) {
        for (int idx = 1; idx < str.size(); idx++) {
            if (str[idx - 1] != str[idx]) return false;
        }
        return true;
    }
    int maximumLength(string input) {
        unordered_map<string, int> frequencyMap;
        for (int start = 0; start < input.size(); start++) {
            for (int end = start; end < input.size(); end++) {
                frequencyMap[input.substr(start, end - start + 1)]++;
            }
        }
        int maxLength = 0;
        for (auto entry : frequencyMap) {
            if (entry.second >= 3 && isSpecial(entry.first)) {
                maxLength = max(maxLength, (int)entry.first.size());
            }
        }
        return (!maxLength) ? -1 : maxLength;
    }
};
