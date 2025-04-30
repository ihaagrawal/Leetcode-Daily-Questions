// 1295. Find Numbers with Even Number of Digits (EASY)
// https://leetcode.com/problems/find-numbers-with-even-number-of-digits/description/?envType=daily-question&envId=2025-04-30

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0; 
        
        for (int num : nums) {
            int digitCount = 0;
            
            while (num != 0) {
                num /= 10;
                digitCount++;
            }
            
            if (digitCount % 2 == 0) count++;
        }
        
        return count;
    }
};
