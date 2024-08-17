// 1937. Maximum Number of Points with Cost (MEDIUM)
// https://leetcode.com/problems/maximum-number-of-points-with-cost/description/?envType=daily-question&envId=2024-08-17


class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int r = points.size(), c = points[0].size();
        if(r == 0) return 0;

        vector<long long> dp(points[0].begin(), points[0].end());
        vector<long long> left(c), right(c);

        for(int i=1;i<r;i++){
            left[0] = dp[0];
            for(int j=1;j<c;j++) left[j] = max(dp[j], left[j-1]-1);

            right[c-1] = dp[c-1];
            for(int j=c-2;j>=0;j--) right[j] = max(dp[j], right[j+1]-1);

            for(int j=0;j<c;j++) dp[j] = points[i][j] + max(left[j], right[j]);
        }

        return *max_element(dp.begin(), dp.end());
    }
};
