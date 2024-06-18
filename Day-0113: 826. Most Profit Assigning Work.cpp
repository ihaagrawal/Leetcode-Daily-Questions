// 826. Most Profit Assigning Work (MEDIUM)
// https://leetcode.com/problems/most-profit-assigning-work/description/?envType=daily-question&envId=2024-06-18


class Solution {
public:

    static bool comp(pair<int, int>& a, pair<int, int>& b){
        return a.first > b.first;
    }

    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = profit.size();
        vector<pair<int, int>> vec(n);

        for(int i=0;i<n;i++){
            vec[i].second = profit[i];
            vec[i].first = difficulty[i]; 
        }

        sort(vec.begin(), vec.end());
        sort(worker.begin(), worker.end());

        int finalProfit = 0;
        for(int i=0,j=0,totalProfit=0;i<worker.size();i++){
            int ability = worker[i];
            while(j < vec.size() && vec[j].first <= ability){
                totalProfit = max(totalProfit, vec[j].second);
                j++;
            }
            finalProfit += totalProfit;
        }

        return finalProfit;
    }
};
