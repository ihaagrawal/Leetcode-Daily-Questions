// 2094. Finding 3-Digit Even Numbers (EASY)
// https://leetcode.com/problems/finding-3-digit-even-numbers/description/?envType=daily-question&envId=2025-05-12

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> uniqueNumbers;
        int n = digits.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (i != j && j != k && i != k) {
                        int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                        if (digits[i] != 0 && digits[k] % 2 == 0) {
                            uniqueNumbers.insert(num);
                        }
                    }
                }
            }
        }
        return vector<int>(uniqueNumbers.begin(), uniqueNumbers.end());
    }
};
