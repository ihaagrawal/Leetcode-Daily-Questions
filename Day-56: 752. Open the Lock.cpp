// 752. Open the Lock (MEDIUM)
// https://leetcode.com/problems/open-the-lock/description/?envType=daily-question&envId=2024-04-22

class Solution {
public:

    void fillNeighbours(queue<string>& q, string& curr, unordered_set<string>& dead){
        for(int i=0;i<4;i++){
            char ch=curr[i];

            char dec=(ch=='0')?'9':ch-1;
            char inc=(ch=='9')?'0':ch+1;

            curr[i]=dec;
            if(!dead.count(curr)){
                dead.insert(curr);
                q.push(curr);
            }

            curr[i]=inc;
            if(!dead.count(curr)){
                dead.insert(curr);
                q.push(curr);
            }

            curr[i]=ch;
        }
    }

    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());

        string start = "0000";
        if(dead.count(start)) return -1;

        queue<string> q;
        q.push(start);

        int level=0;
        while(!q.empty()){
            int n=q.size();

            while(n--){
                string curr = q.front();
                q.pop();
                if(curr==target) return level;

                fillNeighbours(q, curr, dead);
            }
            level++;
        }
        return -1;
    }
};
