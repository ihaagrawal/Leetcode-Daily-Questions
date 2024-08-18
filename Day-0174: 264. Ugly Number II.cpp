// 264. Ugly Number II (MEDIUM)
// https://leetcode.com/problems/ugly-number-ii/description/?envType=daily-question&envId=2024-08-18

class Solution {
public:
    int nthUglyNumber(int n) {
        int div1 = 1, div2 = 1, div3 = 1;
        vector<int> dp(n+1);
        dp[1] = 1;

        for(int i=2;i<=n;i++){
            int a = dp[div1] * 2, b = dp[div2] * 3, c = dp[div3] * 5;
            int next = min({a, b, c});

            dp[i] = next;
            if(next == a) div1++;
            if(next == b) div2++;
            if(next == c) div3++;
        }

        return dp[n];
    }
};
