// 38. Count and Say (MEDIUM)
// https://leetcode.com/problems/count-and-say/description/?envType=daily-question&envId=2025-04-18

class Solution {
public:
    string countAndSay(int n) {
        string result = "1";
        for (int i = 1; i < n; ++i) {
            result = generateNext(result);
        }
        return result;
    }

    string generateNext(const string& s) {
        string result = "";
        int len = s.size(), i = 0;
        while (i < len) {
            char ch = s[i];
            int count = 1;
            while (i < len - 1 && s[i] == s[i + 1]) {
                count++;
                i++;
            }
            i++;
            result += to_string(count) + string(1, ch);
        }
        return result;
    }
};
