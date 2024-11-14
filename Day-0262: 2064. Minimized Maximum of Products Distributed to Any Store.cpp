// 2064. Minimized Maximum of Products Distributed to Any Store (MEDIUM)
// https://leetcode.com/problems/minimized-maximum-of-products-distributed-to-any-store/description/?envType=daily-question&envId=2024-11-14

class Solution {
public:
    bool check(int k, int n, vector<int>& quantities) {
        int store_count = 0;
        for (int quantity : quantities) {
            store_count += (quantity + k - 1) / k;
            if (store_count > n) return false;
        }
        return true;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, high = *max_element(quantities.begin(), quantities.end());
        int result = high;

        while (low <= high) {
            int mid = (low + high) / 2;
            
            if (check(mid, n, quantities)) {
                result = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return result;
    }
};
