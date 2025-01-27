// 1462. Course Schedule IV (MEDIUM)
// https://leetcode.com/problems/course-schedule-iv/description/?envType=daily-question&envId=2025-01-27


class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& qry) {
        // Step 1: Initialize the transitive closure matrix
        vector<vector<bool>> prereq(n, vector<bool>(n, false));
        
        // Step 2: Set direct prerequisites
        for (auto& p : pre) {
            prereq[p[0]][p[1]] = true;
        }
        
        // Step 3: Floyd-Warshall algorithm to compute transitive closure
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    prereq[i][j] = prereq[i][j] || (prereq[i][k] && prereq[k][j]);
                }
            }
        }
        
        // Step 4: Answer the queries
        vector<bool> ans;
        for (auto& q : qry) {
            ans.push_back(prereq[q[0]][q[1]]);
        }
        
        return ans;
    }
};
