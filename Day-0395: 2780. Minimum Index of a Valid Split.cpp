// 2780. Minimum Index of a Valid Split (MEDIUM)
// https://leetcode.com/problems/minimum-index-of-a-valid-split/description/?envType=daily-question&envId=2025-03-27

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n = nums.size();
        int candidate = -1, count = 0;

        for (int num : nums) {
            if (count == 0) {
                candidate = num;
                count = 1;
            } else {
                count += (num == candidate) ? 1 : -1;
            }
        }

        int totalOccurrences = 0;
        for (int num : nums) {
            if (num == candidate) {
                totalOccurrences++;
            }
        }

        if (totalOccurrences <= n / 2) {
            return -1;
        }

        int leftOccurrences = 0;
        for (int i = 0; i < n - 1; ++i) {
            if (nums[i] == candidate) {
                leftOccurrences++;
            }

            int leftSize = i + 1;
            int rightSize = n - leftSize;

            if (leftOccurrences > leftSize / 2 && 
                (totalOccurrences - leftOccurrences) > rightSize / 2) {
                return i;
            }
        }

        return -1;
    }
};
