// 79. Word Search (MEDIUM)
// https://leetcode.com/problems/word-search/description/?envType=daily-question&envId=2024-04-03

class Solution {
public:

    vector<vector<int>> directions{{1,0}, {0,1}, {-1,0}, {0,-1}};

    bool find(vector<vector<char>>& board, int i, int j, string& word, int ind){
        if(ind==word.length()) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='$' || board[i][j]!=word[ind])
            return false;
        
        char temp = board[i][j];
        board[i][j] = '$';

        for(auto& dir: directions){
            int newi = i+dir[0];
            int newj = j+dir[1];

            if(find(board, newi, newj, word, ind+1))
                return true;
        }
        board[i][j]=temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0] && find(board, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
};
