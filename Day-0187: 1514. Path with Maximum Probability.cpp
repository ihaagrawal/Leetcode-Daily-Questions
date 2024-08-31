// 1514. Path with Maximum Probability (MEDIUM)
// https://leetcode.com/problems/path-with-maximum-probability/description/?envType=daily-question&envId=2024-08-31

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {

        vector<vector<pair<int, double>>> adj(n);
        for (int i = 0; i < edges.size(); ++i) {
            int u = edges[i][0];
            int v = edges[i][1];
            double prob = succProb[i];
            adj[u].emplace_back(v, prob);
            adj[v].emplace_back(u, prob);
        }
        
        vector<double> dist(n, 0.0);
        priority_queue<pair<double, int>> pq;

        dist[start_node] = 1.0;
        pq.push({1.0, start_node});

        while(!pq.empty()){
            int node = pq.top().second;
            double prob = pq.top().first;
            pq.pop();

            if(node == end_node) return prob;

            for(auto adjnode : adj[node]){
                double newprob = prob * adjnode.second;
                int newnode = adjnode.first;

                if(newprob > dist[newnode]){
                    dist[newnode] = newprob;
                    pq.push({newprob, newnode});
                }
            }
        }

        return dist[end_node];
    }
};
