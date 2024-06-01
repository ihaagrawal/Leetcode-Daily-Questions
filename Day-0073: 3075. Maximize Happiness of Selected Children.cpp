// 3075. Maximize Happiness of Selected Children (MEDIUM)
// https://leetcode.com/problems/maximize-happiness-of-selected-children/description/?envType=daily-question&envId=2024-05-09

class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        int n = happiness.size();
        sort(happiness.begin(), happiness.end(), greater<int>());
        int i=0;
        long long sum=0;
        int iterations=0;
        for(int i=0;i<k;i++){
            sum += max(happiness[i]-iterations, 0);
            iterations++;
        }
        return sum;
    }
};
