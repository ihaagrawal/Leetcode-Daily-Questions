// 857. Minimum Cost to Hire K Workers (HARD)
// https://leetcode.com/problems/minimum-cost-to-hire-k-workers/description/?envType=daily-question&envId=2024-05-11

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>> ratio;
        int n=quality.size();

        for(int i=0;i<n;i++){
            ratio.emplace_back(static_cast<double>(wage[i]) / quality[i], i);
        }

        sort(ratio.begin(), ratio.end());

        priority_queue<int> pq;
        int qualitySum = 0;
        double maxRate = 0;

        for(int i=0;i<k;i++){
            qualitySum += quality[ratio[i].second];
            maxRate = max(maxRate, ratio[i].first);
            pq.push(quality[ratio[i].second]);
        }

        double res = maxRate * qualitySum;
        for(int i=k;i<n;i++){
            maxRate = max(maxRate, ratio[i].first);
            qualitySum -= pq.top();
            pq.pop();

            qualitySum += quality[ratio[i].second];
            pq.push(quality[ratio[i].second]);
            res = min(res, maxRate*qualitySum);
        }
        return res;

    }
};
