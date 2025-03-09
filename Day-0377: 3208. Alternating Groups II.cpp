// 3208. Alternating Groups II (MEDIUM)
// https://leetcode.com/problems/alternating-groups-ii/description/?envType=daily-question&envId=2025-03-09

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size(), res = 0, count = 1;
        int lastColor = colors[0];

        for (int i = 1; i < n; i++) {
            if (colors[i] == lastColor) count = 1;
            else {
                count++;
                if (count >= k) res++;
            }
            lastColor = colors[i];
        }

        for (int i = 0; i < k - 1; i++) {
            if (colors[i] == lastColor) break;
            count++;
            if (count >= k) res++;
            lastColor = colors[i];
        }

        return res;
    }
};
