// 796. Rotate String (EASY)
// https://leetcode.com/problems/rotate-string/description/?envType=daily-question&envId=2024-11-03


class Solution {
public:
    bool rotateString(string str, string goal) {
        if (str.length() != goal.length()) return false;
        string concatenated = str + str;
        return concatenated.find(goal) != string::npos;
    }
};
