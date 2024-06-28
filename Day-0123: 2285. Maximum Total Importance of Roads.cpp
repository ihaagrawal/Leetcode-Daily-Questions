// 2285. Maximum Total Importance of Roads (MEDIUM)
// https://leetcode.com/problems/maximum-total-importance-of-roads/description/?envType=daily-question&envId=2024-06-28

class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> indeg(n, 0);

        for(auto& road : roads){
            indeg[road[0]]++;
            indeg[road[1]]++;
        }

        vector<int> city(n);
        for(int i=0;i<n;i++) city[i] = i;
        sort(city.begin(), city.end(), [&indeg](int a, int b) {
            return indeg[a] > indeg[b];
        });
        
        long long importance = 0;
        for(int i=0;i<n;i++) importance += (long long)(n-i) * indeg[city[i]];

        return importance;
    }
};
