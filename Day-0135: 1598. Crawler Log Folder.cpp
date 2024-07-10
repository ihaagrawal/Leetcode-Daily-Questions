// 1598. Crawler Log Folder (EASY)
// https://leetcode.com/problems/crawler-log-folder/description/?envType=daily-question&envId=2024-07-10


class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = logs.size();
        int steps = 0;

        for(int i=0;i<n;i++){
            if(logs[i] == "../"){
                if(steps > 0) steps -= 1;
                else steps = 0;
            }else if(logs[i] == "./") steps += 0;
            else steps += 1;
        }
        
        return steps;
    }
};
