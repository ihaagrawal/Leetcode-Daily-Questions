// 773. Sliding Puzzle (HARD)
// https://leetcode.com/problems/sliding-puzzle/description/?envType=daily-question&envId=2024-11-25


class Solution {
public:
    vector<int> rows = {1, 0, -1, 0};
    vector<int> cols = {0, 1, 0, -1};
    
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = "";
        string target = "123450";
        for (auto& row : board)
            for (int num : row)
                start += to_string(num);
        
        queue<pair<string, int>> q; 
        unordered_set<string> visited;
        q.push({start, 0});
        visited.insert(start);
        
        while (!q.empty()) {
            auto [current, steps] = q.front();
            q.pop();
            
            if (current == target) return steps;
            
            int zero_pos = current.find('0');
            int row = zero_pos / 3;
            int col = zero_pos % 3;
            
            for (int i = 0; i < 4; i++) {
                int nrow = row + rows[i];
                int ncol = col + cols[i];
                if (nrow >= 0 && nrow < 2 && ncol >= 0 && ncol < 3) {
                    string next = current;
                    swap(next[zero_pos], next[nrow * 3 + ncol]);
                    
                    if (!visited.count(next)) {
                        q.push({next, steps + 1});
                        visited.insert(next);
                    }
                }
            }
        }
        
        return -1;
    }
};
