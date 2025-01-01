// 1422. Maximum Score After Splitting a String (EASY)
// https://leetcode.com/problems/maximum-score-after-splitting-a-string/description/?envType=daily-question&envId=2025-01-01

class Solution {
public:
    int maxScore(string s) {
        int totalOnes = count(s.begin(), s.end(), '1');
        int maxScore = 0;
        int zeroCount = 0, oneCount = 0;

        for (int i = 0; i < s.size() - 1; ++i) {
            if (s[i] == '0') zeroCount++;
            else oneCount++;

            int score = zeroCount + (totalOnes - oneCount);
            maxScore = max(maxScore, score);
        }

        return maxScore;
    }
};
