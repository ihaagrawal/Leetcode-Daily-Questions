// 1760. Minimum Limit of Balls in a Bag (MEDIUM)
// https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/description/?envType=daily-question&envId=2024-12-07


class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1, right = *max_element(nums.begin(), nums.end()), result = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canDivide(nums, maxOperations, mid)) {
                result = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return result;
    }

private:
    bool canDivide(const vector<int>& nums, int maxOperations, int penalty) {
        int operations = 0;

        for (int balls : nums) {
            operations += (balls - 1) / penalty;
            if (operations > maxOperations) {
                return false;
            }
        }

        return true;
    }
};
