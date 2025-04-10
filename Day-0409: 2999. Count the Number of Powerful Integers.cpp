// 2999. Count the Number of Powerful Integers (HARD)
// https://leetcode.com/problems/count-the-number-of-powerful-integers/description/?envType=daily-question&envId=2025-04-10


class Solution {
public:
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        string l = to_string(start), h = to_string(finish);
        while (l.size() < h.size()) l = "0" + l;
        int n = h.size(), sl = s.size(), pl = n - sl;

        vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(2, vector<long long>(2, -1)));

        function<long long(int, bool, bool, bool)> dfs = [&](int i, bool tl, bool th, bool ms) -> long long {
            if (i == n) return ms;
            if (dp[i][tl][th] != -1 && !ms) return dp[i][tl][th];

            int lo = tl ? l[i] - '0' : 0, hi = th ? h[i] - '0' : 9;
            long long res = 0;

            for (int d = lo; d <= hi; ++d) {
                if (d > limit) break;
                bool ntl = tl && d == lo, nth = th && d == hi;
                if (i < pl) {
                    res += dfs(i + 1, ntl, nth, false);
                } else {
                    int si = i - pl;
                    if (si < sl && d == s[si] - '0') {
                        res += dfs(i + 1, ntl, nth, true);
                    } else if (si >= sl) {
                        res += dfs(i + 1, ntl, nth, ms);
                    }
                }
            }

            if (!tl && !th && !ms) dp[i][tl][th] = res;
            return res;
        };

        return dfs(0, true, true, false);
    }
};
