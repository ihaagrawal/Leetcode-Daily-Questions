// 633. Sum of Square Numbers (MEDIUM)
// https://leetcode.com/problems/sum-of-square-numbers/description/?envType=daily-question&envId=2024-06-17

class Solution {
public:
    bool judgeSquareSum(int c) {
        long long int max = sqrt(c);
        for(int i=0;i<=max;i++){
            long long int first = i*i;
            long long int remaining = c - first;
            long long int j = sqrt(remaining);
            if(j*j == remaining) return true;
        }
        return false;
    }
};
