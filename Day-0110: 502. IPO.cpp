// 502. IPO (HARD)
// https://leetcode.com/problems/ipo/description/?envType=daily-question&envId=2024-06-15

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();

        vector<pair<int,int>> data(n);
        for(int i=0;i<n;i++){
            data[i].first = capital[i];
            data[i].second = profits[i];
        }

        sort(data.begin(), data.end());

        priority_queue<int> pq;
        int j = 0;
        for(int i=0;i<k;i++){
            while(j<n && data[j].first <= w){
                pq.push(data[j].second);
                j++;
            }

            if(pq.empty()) break;

            w += pq.top();
            pq.pop();
        }

        return w;
        
    }
};
