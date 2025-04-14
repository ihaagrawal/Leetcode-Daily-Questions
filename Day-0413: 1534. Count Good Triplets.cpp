// 1534. Count Good Triplets (EASY)
// https://leetcode.com/problems/count-good-triplets/description/?envType=daily-question&envId=2025-04-14

class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int count = 0;
        int n = arr.size();

        for (int j = 1; j < n - 1; ++j) {
            map<int, int> leftFreq, rightFreq;

            for (int i = 0; i < j; ++i) leftFreq[arr[i]]++;
            for (int k = j + 1; k < n; ++k) rightFreq[arr[k]]++;

            for (auto& left : leftFreq) {
                if (abs(left.first - arr[j]) <= a) {
                    for (auto& right : rightFreq) {
                        if (abs(arr[j] - right.first) <= b && abs(left.first - right.first) <= c) {
                            count += left.second * right.second;
                        }
                    }
                }
            }
        }

        return count;
    }
};
