// 2127. Maximum Employees to Be Invited to a Meeting (HARD)
// https://leetcode.com/problems/maximum-employees-to-be-invited-to-a-meeting/description/?envType=daily-question&envId=2025-01-26

class Solution {
public:
    int maximumInvitations(vector<int>& favorite) {
        int numPeople = favorite.size();
        vector<vector<int>> reverseGraph(numPeople);
        
        // Build the reversed graph
        for (int person = 0; person < numPeople; ++person) {
            reverseGraph[favorite[person]].push_back(person);
        }

        // Helper function for BFS
        auto performBFS = [&](int startNode, unordered_set<int>& visitedNodes) -> int {
            queue<pair<int, int>> bfsQueue;
            bfsQueue.push({startNode, 0});
            int maxDepth = 0;

            while (!bfsQueue.empty()) {
                auto [currentNode, currentDepth] = bfsQueue.front();
                bfsQueue.pop();

                for (int neighbor : reverseGraph[currentNode]) {
                    if (visitedNodes.count(neighbor)) {
                        continue;
                    }

                    visitedNodes.insert(neighbor);
                    bfsQueue.push({neighbor, currentDepth + 1});
                    maxDepth = max(maxDepth, currentDepth + 1);
                }
            }

            return maxDepth;
        };

        int maxCycleLength = 0;
        int totalTwoCycleInvitations = 0;
        vector<bool> isVisited(numPeople, false);

        // Identify all cycles
        for (int person = 0; person < numPeople; ++person) {
            if (!isVisited[person]) {
                unordered_map<int, int> visitOrder;
                int currentPerson = person;
                int distance = 0;

                while (true) {
                    if (isVisited[currentPerson]) {
                        break;
                    }

                    isVisited[currentPerson] = true;
                    visitOrder[currentPerson] = distance++;
                    int nextPerson = favorite[currentPerson];

                    if (visitOrder.count(nextPerson)) {  // Cycle detected
                        int cycleLength = distance - visitOrder[nextPerson];
                        maxCycleLength = max(maxCycleLength, cycleLength);

                        if (cycleLength == 2) {
                            unordered_set<int> visitedNodes = {currentPerson, nextPerson};
                            totalTwoCycleInvitations += 2 + performBFS(nextPerson, visitedNodes) + performBFS(currentPerson, visitedNodes);
                        }

                        break;
                    }

                    currentPerson = nextPerson;
                }
            }
        }

        return max(maxCycleLength, totalTwoCycleInvitations);
    }
};
