// 2179. Count Good Triplets in an Array (HARD)
// https://leetcode.com/problems/count-good-triplets-in-an-array/description/?envType=daily-question&envId=2025-04-15

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        
        unordered_map<int, int> pos1;
        for (int i = 0; i < n; ++i) {
            pos1[nums1[i]] = i;
        }
        
        vector<int> transformed(n);
        for (int i = 0; i < n; ++i) {
            transformed[i] = pos1[nums2[i]];
        }
        
        vector<int> fenwick(n + 1, 0);
        
        auto update = [&](int index, int value) {
            for (++index; index <= n; index += index & -index) {
                fenwick[index] += value;
            }
        };
        
        auto query = [&](int index) {
            int sum = 0;
            for (++index; index > 0; index -= index & -index) {
                sum += fenwick[index];
            }
            return sum;
        };
        
        long long result = 0;
        vector<int> leftCount(n, 0); 
        
        for (int i = 0; i < n; ++i) {
            leftCount[i] = query(transformed[i] - 1);
            update(transformed[i], 1);
        }
        
        fill(fenwick.begin(), fenwick.end(), 0);
        
        for (int i = n - 1; i >= 0; --i) {
            int rightCount = query(n - 1) - query(transformed[i]);
            result += static_cast<long long>(leftCount[i]) * rightCount;
            update(transformed[i], 1);
        }
        
        return result;
    }
};
