// 1524. Number of Sub-arrays With Odd Sum (MEDIUM)
// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/?envType=daily-question&envId=2025-02-25

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int oddCount = 0, evenCount = 1; 
        int currSum = 0, result = 0;

        for (int num : arr) {
            currSum += num;

            if (currSum % 2 == 0) {
                result = (result + oddCount) % MOD;
                evenCount++;
            } else {
                result = (result + evenCount) % MOD;
                oddCount++;
            }
        }

        return result;
    }
};
