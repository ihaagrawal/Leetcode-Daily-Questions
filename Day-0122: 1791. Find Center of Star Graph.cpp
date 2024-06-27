// 1791. Find Center of Star Graph (EASY)
// https://leetcode.com/problems/find-center-of-star-graph/description/?envType=daily-question&envId=2024-06-27

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n = edges.size(), m = edges[0].size();

        if(n <= 1) return -1;

        if(edges[0][0] == edges[1][0] || edges[0][0] == edges[1][1]) return edges[0][0];
        if(edges[0][1] == edges[1][0] || edges[0][1] == edges[1][1]) return edges[0][1];
        
        return -1;
    }
};
