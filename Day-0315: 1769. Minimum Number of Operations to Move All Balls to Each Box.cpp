// 1769. Minimum Number of Operations to Move All Balls to Each Box (MEDIUM)
// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/?envType=daily-question&envId=2025-01-06


class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<vector<int>> dist(n, vector<int>(n, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                dist[i][j] = abs(i-j);
            }
        }

        vector<int> result(n, 0);
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=0;j<n;j++){
                if(boxes[j] == '1') sum += dist[i][j];
            }
            result[i] = sum;
        }

        return result;
    }
};
