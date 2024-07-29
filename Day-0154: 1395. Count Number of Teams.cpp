// 1395. Count Number of Teams (MEDIUM)
// https://leetcode.com/problems/count-number-of-teams/description/?envType=daily-question&envId=2024-07-29


class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        int count = 0;

        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int k=j+1;k<n;k++){
                    if(rating[i] < rating[j] && rating[j] < rating[k])count++;
                    else if(rating[i] > rating[j] && rating[j] > rating[k]) count++;
                }
            }
        }

        return count;
    }
};
