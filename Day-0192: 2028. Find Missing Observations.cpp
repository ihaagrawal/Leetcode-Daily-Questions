// 2028. Find Missing Observations (MEDIUM)
// https://leetcode.com/problems/find-missing-observations/description/?envType=daily-question&envId=2024-09-05

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size(), sum = accumulate(rolls.begin(), rolls.end(), 0);
        int total = (n + m ) * mean, rem = total - sum;

        if(6 * n < rem || rem < n) return {};
        int quotient = rem / n;
        int remainder = rem % n;

        vector<int> result(n, quotient);
        fill(result.begin(), result.begin() + remainder, quotient + 1);
        return result;
    }
};
