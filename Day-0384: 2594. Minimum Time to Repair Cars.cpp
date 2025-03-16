// 2594. Minimum Time to Repair Cars (MEDIUM)
// https://leetcode.com/problems/minimum-time-to-repair-cars/description/?envType=daily-question&envId=2025-03-16

class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1;
        long long right = 1LL * ranks[0] * cars * cars;
        long long result = right;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            if (canRepairAll(ranks, cars, mid)) {
                result = mid;
                right = mid - 1;
            } else left = mid + 1;
        }

        return result;
    }

private:
    bool canRepairAll(const vector<int>& ranks, int cars, long long time) {
        long long totalCars = 0;

        for (int rank : ranks) {
            totalCars += std::sqrt(time / rank);
            if (totalCars >= cars) return true;
        }

        return totalCars >= cars;
    }
};
