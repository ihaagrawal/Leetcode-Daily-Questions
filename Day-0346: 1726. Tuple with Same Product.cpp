// 1726. Tuple with Same Product (MEDIUM)
// https://leetcode.com/problems/tuple-with-same-product/description/?envType=daily-question&envId=2025-02-06


#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> productCount;
        int n = nums.size();
        int result = 0;

        // Count all products of pairs
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int product = nums[i] * nums[j];
                productCount[product]++;
            }
        }

        // Calculate the number of tuples for each product
        for (const auto& entry : productCount) {
            int freq = entry.second;
            if (freq > 1) {
                // Number of ways to pick 2 pairs out of `freq` pairs
                result += (freq * (freq - 1) / 2) * 8; // Each pair contributes 8 tuples
            }
        }

        return result;
    }
};
