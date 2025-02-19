// 1415. The k-th Lexicographical String of All Happy Strings of Length n (MEDIUM)
// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/description/?envType=daily-question&envId=2025-02-19


class Solution {
public:
    void generateHappyStrings(int n, string current, vector<string>& happyStrings) {
        if (current.size() == n) {
            happyStrings.push_back(current);
            return;
        }

        for (char c : {'a', 'b', 'c'}) {
            if (current.empty() || current.back() != c) {
                generateHappyStrings(n, current + c, happyStrings);
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> happyStrings;
        generateHappyStrings(n, "", happyStrings);

        if (k > happyStrings.size()) return "";
        return happyStrings[k - 1];
    }
};
