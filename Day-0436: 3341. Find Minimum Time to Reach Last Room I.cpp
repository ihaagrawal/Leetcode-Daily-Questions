// 3341. Find Minimum Time to Reach Last Room I (MEDIUM)
// https://leetcode.com/problems/find-minimum-time-to-reach-last-room-i/description/?envType=daily-question&envId=2025-05-07

using int3 = tuple<int, int, int>; 
const static int d[5] = {0, 1, 0, -1, 0};

class Solution {
public:
    inline static bool isOutside(int i, int j, int n, int m) {
        return i < 0 || i >= n || j < 0 || j >= m;
    }

    static int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        vector<vector<int>> time(n, vector<int>(m, INT_MAX));
        priority_queue<int3, vector<int3>, greater<int3>> pq;

        pq.emplace(0, 0, 0);
        time[0][0] = 0;

        while (!pq.empty()) {
            auto [t, i, j] = pq.top();
            pq.pop();

            if (i == n - 1 && j == m - 1)
                return t;

            for (int a = 0; a < 4; a++) {
                int r = i + d[a], s = j + d[a + 1];
                if (isOutside(r, s, n, m)) continue;

                int nextTime = max(t, moveTime[r][s]) + 1;

                if (nextTime < time[r][s]) {
                    time[r][s] = nextTime;
                    pq.emplace(nextTime, r, s);
                }
            }
        }

        return -1;
    }
};
