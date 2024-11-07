// 2275. Largest Combination With Bitwise AND Greater Than Zero (MEDIUM)
// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/description/?envType=daily-question&envId=2024-11-07


class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        map<int, int> mp;
        int result = 0;
        for(int can : candidates){
            for(int i=0;i<=30;i++){
                if((1 << i & can) > 0) mp[i]++;
            }
        }

        for(auto i=mp.begin();i!=mp.end();i++){
            result = max(i->second, result);
        }

        return result;
    }
};
