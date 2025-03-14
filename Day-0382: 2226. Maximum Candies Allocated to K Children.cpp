// 2226. Maximum Candies Allocated to K Children (MEDIUM)
// https://leetcode.com/problems/maximum-candies-allocated-to-k-children/description/?envType=daily-question&envId=2025-03-14

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long long left = 1, right = *max_element(candies.begin(), candies.end());
        int result = 0;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            if (canDistribute(candies, k, mid)) {
                result = mid;
                left = mid + 1;
            } else right = mid - 1;
        }

        return result;
    }

private:
    bool canDistribute(vector<int>& candies, long long k, long long mid) {
        long long count = 0;

        for (const int& pile : candies) {
            count += pile / mid;
            if (count >= k) return true;
        }

        return count >= k;
    }
};
