// 2045. Second Minimum Time to Reach Destination (HARD)
// https://leetcode.com/problems/second-minimum-time-to-reach-destination/description/?envType=daily-question&envId=2024-07-28


class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        // Create an adjacency list for the graph
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0] - 1].push_back(edge[1] - 1);
            adj[edge[1] - 1].push_back(edge[0] - 1);
        }

        // Priority queues to store the minimum and second minimum times to reach each node
        vector<priority_queue<int>> travelTimes(n);
        for (int i = 0; i < n; i++) {
            travelTimes[i].push(INT_MAX);  // Initialize with a large number
        }

        // Priority queue for the BFS traversal
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});  // {time, node}
        travelTimes[0].pop();
        travelTimes[0].push(0);

        while (!pq.empty()) {
            int currentTime = pq.top().first;
            int currentNode = pq.top().second;
            pq.pop();

            int cycles = currentTime / change;
            if (cycles % 2 == 1) {
                currentTime += (change - (currentTime % change));  // Wait for green light
            }

            for (int neighbor : adj[currentNode]) {
                int newTime = currentTime + time;
                if (travelTimes[neighbor].top() == INT_MAX) {
                    travelTimes[neighbor].pop();
                    travelTimes[neighbor].push(newTime);
                    pq.push({newTime, neighbor});
                } else if (travelTimes[neighbor].size() < 2 && travelTimes[neighbor].top() != newTime) {
                    travelTimes[neighbor].push(newTime);
                    pq.push({newTime, neighbor});
                } else if (travelTimes[neighbor].top() > newTime) {
                    travelTimes[neighbor].pop();
                    travelTimes[neighbor].push(newTime);
                    pq.push({newTime, neighbor});
                }
            }
        }

        return travelTimes[n - 1].top();
    }
};
