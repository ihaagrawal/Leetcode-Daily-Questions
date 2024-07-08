// 1823. Find the Winner of the Circular Game (MEDIUM)
// https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/?envType=daily-question&envId=2024-07-08

class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> que;
        for(int i=1;i<=n;i++) que.push(i);

        while(que.size() != 1){
            for(int i=0;i<k-1;i++){
                int num = que.front();
                que.pop();
                que.push(num);
            }
            if(que.size() == 1) break;
            que.pop();
        }

        return que.front();
    }
};
