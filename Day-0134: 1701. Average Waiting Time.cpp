// 1701. Average Waiting Time (MEDIUM)
// https://leetcode.com/problems/average-waiting-time/description/?envType=daily-question&envId=2024-07-09


class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        if(n == 0) return -1;
        int lastEnd = customers[0][0];
        double sum = 0;

        for(int i=0;i<n;i++){
            int start = customers[i][0], end = customers[i][1];
            lastEnd = max(start, lastEnd) + end;
            sum += (lastEnd - start);
        }

        double avg = (double)sum / n;
        return avg;
    }
};
