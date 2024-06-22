// 1248. Count Number of Nice Subarrays (MEDIUM)
// https://leetcode.com/problems/count-number-of-nice-subarrays/description/?envType=daily-question&envId=2024-06-22

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0, nice = 0;
        int left = 0;
        int oddCount = 0;
        int oddPrefixCount = 0;

        for (int right = 0; right < n; right++) {
            if (nums[right] % 2 != 0) {
                oddCount++;
                oddPrefixCount = 0;
            }

            while (oddCount == k) {
                oddPrefixCount++;
                if (nums[left] % 2 != 0) {
                    oddCount--;
                }
                left++;
            }

            nice += oddPrefixCount;
        }

        return nice;
    }
};
