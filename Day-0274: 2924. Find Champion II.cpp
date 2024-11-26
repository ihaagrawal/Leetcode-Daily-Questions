// 2924. Find Champion II (MEDIUM)
// https://leetcode.com/problems/find-champion-ii/description/?envType=daily-question&envId=2024-11-26

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n, 0);
        for (const auto& edge : edges) inDegree[edge[1]]++;
        
        int champion = -1;
        for (int i = 0; i < n; ++i) {
            if (inDegree[i] == 0) {
                if (champion != -1) return -1;
                champion = i;
            }
        }
        
        return champion;
    }
};
