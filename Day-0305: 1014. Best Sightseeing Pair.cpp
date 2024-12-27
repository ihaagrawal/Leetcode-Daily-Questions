// 1014. Best Sightseeing Pair (MEDIUM)
// https://leetcode.com/problems/best-sightseeing-pair/description/?envType=daily-question&envId=2024-12-27

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxScore = 0;
        int maxPrev = values[0];
        
        for (int j = 1; j < values.size(); ++j) {
            maxScore = max(maxScore, maxPrev + values[j] - j);
            maxPrev = max(maxPrev, values[j] + j);
        }
        
        return maxScore;
    }
};
