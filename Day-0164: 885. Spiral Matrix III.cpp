// 885. Spiral Matrix III (MEDIUM)
// https://leetcode.com/problems/spiral-matrix-iii/description/?envType=daily-question&envId=2024-08-08

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> result;
        result.push_back({rStart, cStart});
        int cells = rows * cols;
        vector<int> r = {0, 1, 0, -1};
        vector<int> c = {1, 0, -1, 0};
        
        int steps = 1, dir = 0;
        while(result.size() < cells){
            for(int i=0;i<steps;i++){
                rStart += r[dir];
                cStart += c[dir];

                if(rStart >=0 && rStart < rows && cStart >= 0 && cStart < cols){
                    result.push_back({rStart, cStart});
                }
            }

            dir = (dir + 1) % 4;
            if(dir == 0 || dir == 2) steps++; 
        }
        
        return result;
    }
};
