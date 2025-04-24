// 1399. Count Largest Group (EASY)
// https://leetcode.com/problems/count-largest-group/description/?envType=daily-question&envId=2025-04-23

#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int countLargestGroup(int n) {
        std::unordered_map<int, int> digitSumFreq; 
        
        for (int i = 1; i <= n; ++i) {
            int sum = 0, num = i;
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            digitSumFreq[sum]++;
        }
        
        int maxFreq = 0;
        for (const auto& pair : digitSumFreq) {
            maxFreq = std::max(maxFreq, pair.second);
        }
        
        int count = 0;
        for (const auto& pair : digitSumFreq) {
            if (pair.second == maxFreq) {
                count++;
            }
        }
        
        return count;
    }
};
