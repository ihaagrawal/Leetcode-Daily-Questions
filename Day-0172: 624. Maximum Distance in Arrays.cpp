// 624. Maximum Distance in Arrays (MEDIUM)
// https://leetcode.com/problems/maximum-distance-in-arrays/description/


class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int n = arrays.size(), dist = 0;
        int mini = arrays[0][0], maxi = arrays[0][arrays[0].size()-1];

        for(int i=1;i<n;i++){
            int first = arrays[i][0], last = arrays[i][arrays[i].size()-1];
            dist = max(dist, max(last-mini, maxi-first));
            mini = min(mini, first);
            maxi = max(maxi, last);
        }

        return dist;
    }
};
