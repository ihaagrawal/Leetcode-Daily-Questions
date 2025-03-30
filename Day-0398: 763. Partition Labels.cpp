// 763. Partition Labels (MEDIUM)
// https://leetcode.com/problems/partition-labels/description/?envType=daily-question&envId=2025-03-30

class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastOccurrence(26, -1);
        vector<int> result;
        
        for (int i = 0; i < s.length(); i++) {
            lastOccurrence[s[i] - 'a'] = i;
        }
        
        int start = 0, end = 0;
        for (int i = 0; i < s.length(); i++) {
            end = max(end, lastOccurrence[s[i] - 'a']);
            if (i == end) {
                result.push_back(end - start + 1);
                start = i + 1;
            }
        }
        
        return result;
    }
};
