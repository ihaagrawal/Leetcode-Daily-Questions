// 3097. Shortest Subarray With OR at Least K II (MEDIUM)
// https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/description/?envType=daily-question&envId=2024-11-10


class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> bitCount(32, 0);
        int left = 0, right = 0, minLength = INT_MAX;

        while (right < nums.size()) {
            updateBitCount(bitCount, nums[right], 1);
            while (left <= right && calculateOR(bitCount) >= k) {
                minLength = min(minLength, right - left + 1);
                updateBitCount(bitCount, nums[left], -1);
                left++;
            }
            right++;
        }

        return minLength == INT_MAX ? -1 : minLength;
    }

private:
    void updateBitCount(vector<int>& bitCount, int num, int change) {
        for (int i = 0; i < 32; i++) {
            if ((num >> i) & 1) {
                bitCount[i] += change;
            }
        }
    }

    int calculateOR(const vector<int>& bitCount) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            if (bitCount[i] > 0) {
                result |= (1 << i);
            }
        }
        return result;
    }
};
