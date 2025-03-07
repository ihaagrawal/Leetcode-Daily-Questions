// 2523. Closest Prime Numbers in Range (MEDIUM)
// https://leetcode.com/problems/closest-prime-numbers-in-range/description/?envType=daily-question&envId=2025-03-07


class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = isPrime[1] = false; 
        
        for (int i = 2; i <= sqrt(right); ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        vector<int> primesInRange;
        for (int i = max(2, left); i <= right; ++i) {
            if (isPrime[i]) {
                primesInRange.push_back(i);
            }
        }
        
        int minDiff = INT_MAX;
        vector<int> result = {-1, -1};
        
        for (size_t i = 1; i < primesInRange.size(); ++i) {
            int diff = primesInRange[i] - primesInRange[i - 1];
            if (diff < minDiff) {
                minDiff = diff;
                result = {primesInRange[i - 1], primesInRange[i]};
            }
        }
        
        return result;
    }
};
