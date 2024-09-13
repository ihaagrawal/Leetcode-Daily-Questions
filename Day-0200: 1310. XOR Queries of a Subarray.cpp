// 1310. XOR Queries of a Subarray (MEDIUM)
// https://leetcode.com/problems/xor-queries-of-a-subarray/description/?envType=daily-question&envId=2024-09-13

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<int> result;

        for(int i=0;i<n;i++){
            int x = queries[i][0], y = queries[i][1];
            int xr = 0;
            for(int j=x;j<=y;j++) xr ^= arr[j];
            result.push_back(xr);
        }

        return result;
    }
};
