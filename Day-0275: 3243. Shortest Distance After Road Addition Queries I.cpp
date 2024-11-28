// 3243. Shortest Distance After Road Addition Queries I (MEDIUM)
// https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/description/?envType=daily-question&envId=2024-11-27


class Solution {
public:

    int dij(int n, vector<vector<pair<int, int>>>& adj){
        vector<int> distance(n, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        distance[0] = 0;
        pq.push({0, 0});

        while(!pq.empty()){
            int v = pq.top().second, u = pq.top().first;
            pq.pop();

            if(u > distance[v]) continue;

            for(auto& adjnode : adj[v]){
                int e = adjnode.first, wt = adjnode.second;
                if(distance[v] + wt < distance[e]){
                    distance[e] = distance[v] + wt;
                    pq.push({distance[e], e});
                }
            }
        }

        return distance[n-1];
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> result;
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0;i<n-1;i++) adj[i].push_back({i+1, 1});

        for(auto query : queries){
            int u = query[0], v = query[1];
            adj[u].push_back({v, 1});
            int dist = dij(n, adj);
            result.push_back(dist);
        }

        return result;
    }
};
