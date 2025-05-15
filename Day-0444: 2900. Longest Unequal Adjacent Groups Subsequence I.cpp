// 2900. Longest Unequal Adjacent Groups Subsequence I (EASY)
// https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/description/?envType=daily-question&envId=2025-05-15

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<pair<string, int>> corr(n);

        for(int i=0;i<n;i++){
            corr[i].first = words[i];
            corr[i].second = groups[i];
        }

        vector<string> result;
        int last = -1;
        for(int i=0;i<n;i++){
            if(last == -1){
                result.push_back(corr[i].first);
                last = corr[i].second;
            }else if(last == corr[i].second) continue;
            else{
                result.push_back(corr[i].first);
                last = corr[i].second;
            }
        }

        return result;
    }
};
