// 1861. Rotating the Box (MEDIUM)
// https://leetcode.com/problems/rotating-the-box/description/?envType=daily-question&envId=2024-11-23


class Solution {
public:

    void rotate(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<char>> rotated(m, vector<char>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                rotated[j][n - i - 1] = matrix[i][j];
            }
        }

        matrix = rotated; 
    }

    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        
        for (int i = 0; i < n; i++) {
            int empty = m - 1; 
            for (int j = m - 1; j >= 0; j--) {
                if (box[i][j] == '*') empty = j - 1; 
                else if (box[i][j] == '#') {
                    swap(box[i][j], box[i][empty]);
                    empty--;
                }
            }
        }

        rotate(box);
        return box;
    }
};
