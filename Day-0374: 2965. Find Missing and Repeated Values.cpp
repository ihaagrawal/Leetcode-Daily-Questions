// 2965. Find Missing and Repeated Values (EASY)
// https://leetcode.com/problems/find-missing-and-repeated-values/description/?envType=daily-question&envId=2025-03-06

class Solution {
public:

    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        vector<int> count(pow(n,2)+1, 0);
        int repeating = -1, missing = -1;
        
        for(int i = 0; i < n; i++) count[arr[i]]++;
        for(int i = 1; i <= n; i++) {
            if(count[i] == 0) missing = i;
            else if(count[i] > 1) repeating = i;
        }
        
        return {repeating, missing};
    }

    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size(), ind = 0;
        vector<int> temp(n*n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp[ind++] = grid[i][j];
            }
        }
        return findTwoElement(temp);
    }
};
