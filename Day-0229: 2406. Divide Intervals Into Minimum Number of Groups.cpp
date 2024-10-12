// 2406. Divide Intervals Into Minimum Number of Groups (MEDIUM)
// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/description/?envType=daily-question&envId=2024-10-12

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int, int> events;
        
        for (auto& interval : intervals) {
            events[interval[0]]++;        
            events[interval[1] + 1]--;    
        }
        
        int maxGroups = 0, currentGroups = 0;
        
        for (auto& event : events) {
            currentGroups += event.second;
            maxGroups = max(maxGroups, currentGroups);
        }
        
        return maxGroups;
    }
};
