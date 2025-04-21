// 2145. Count the Hidden Sequences (MEDIUM)
// https://leetcode.com/problems/count-the-hidden-sequences/description/?envType=daily-question&envId=2025-04-21

class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long current = 0;
        long long minHidden = 0, maxHidden = 0;
        
        for (int diff : differences) {
            current += diff;
            minHidden = min(minHidden, current);
            maxHidden = max(maxHidden, current);
        }
        
        long long startLowerBound = lower - minHidden;
        long long startUpperBound = upper - maxHidden;
        
        if (startLowerBound > startUpperBound) return 0;
        
        return startUpperBound - startLowerBound + 1;
    }
};
