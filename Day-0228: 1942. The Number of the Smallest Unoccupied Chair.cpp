// 1942. The Number of the Smallest Unoccupied Chair (MEDIUM)
// https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/description/?envType=daily-question&envId=2024-10-11

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        
        vector<pair<int, int>> at;
        for(int i = 0; i < n; i++) {
            at.push_back({times[i][0], i});
        }
        sort(at.begin(), at.end());

        priority_queue<int, vector<int>, greater<int>> avail;
        for(int i = 0; i < n; i++) avail.push(i);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto &it : at) {
            int arr = it.first, ind = it.second;
            
            while(!pq.empty() && pq.top().first <= arr) {
                avail.push(pq.top().second);
                pq.pop();
            }

            int chair = avail.top();
            avail.pop();

            pq.push({times[ind][1], chair});

            if(ind == targetFriend) return chair;
        }

        return -1;
    }
};
