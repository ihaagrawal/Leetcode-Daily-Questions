// 2661. First Completely Painted Row or Column (MEDIUM)
// https://leetcode.com/problems/first-completely-painted-row-or-column/description/?envType=daily-question&envId=2025-01-20


class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int len = arr.size(), n = mat.size(), m = mat[0].size();
        vector<int> rows(n, 0), cols(m, 0);
        vector<pair<int, int>> coors(m * n);

        // Build the coordinates of matrix values
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int index = mat[i][j] - 1; // Adjust if matrix values are 1-based
                coors[index].first = i;
                coors[index].second = j;
            }
        }

        // Process the array
        for (int i = 0; i < len; i++) {
            int num = arr[i] - 1; // Adjust if array values are 1-based
            int x = coors[num].first, y = coors[num].second;
            rows[x]++;
            cols[y]++;
            if (rows[x] == m || cols[y] == n) {
                return i;
            }
        }

        return -1;
    }
};
