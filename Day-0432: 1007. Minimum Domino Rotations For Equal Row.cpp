// 1007. Minimum Domino Rotations For Equal Row (MEDIUM)
// https://leetcode.com/problems/minimum-domino-rotations-for-equal-row/description/?envType=daily-question&envId=2025-05-03

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size(), dupes = 0;
        map<int, set<int>> mp;

        for(int i=0;i<n;i++){
            if(tops[i] == bottoms[i]) dupes++;
            mp[tops[i]].insert(i);
            mp[bottoms[i]].insert(i);
        }

        int ele = -1;
        for(auto it : mp){
            if(it.second.size() == n) ele = it.first;
        }

        if(ele == -1) return ele;

        int top = 0, bottom = 0;
        for(int i=0;i<n;i++){
            if(tops[i] == ele) top++;
            if(bottoms[i] == ele) bottom++;
        }

        return min(top-dupes, bottom-dupes);
    }
};
