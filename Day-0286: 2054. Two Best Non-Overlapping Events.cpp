// 2054. Two Best Non-Overlapping Events (MEDIUM)
// https://leetcode.com/problems/two-best-non-overlapping-events/description/?envType=daily-question&envId=2024-12-08


class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& e) {
        int n = e.size();
        
        sort(e.begin(), e.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });
        
        vector<int> sMax(n);
        sMax[n - 1] = e[n - 1][2];
        
        for (int i = n - 2; i >= 0; --i) {
            sMax[i] = max(e[i][2], sMax[i + 1]);
        }
        
        int mSum = 0;
        
        for (int i = 0; i < n; ++i) {
            int l = i + 1, r = n - 1;
            int ni = -1;
            
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (e[mid][0] > e[i][1]) {
                    ni = mid;
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
            
            if (ni != -1) {
                mSum = max(mSum, e[i][2] + sMax[ni]);
            }
            
            mSum = max(mSum, e[i][2]);
        }
        
        return mSum;
    }
};
