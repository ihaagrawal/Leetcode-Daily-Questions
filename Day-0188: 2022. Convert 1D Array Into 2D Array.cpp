// 2022. Convert 1D Array Into 2D Array (EASY)
// https://leetcode.com/problems/convert-1d-array-into-2d-array/description/?envType=daily-question&envId=2024-09-01

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int len = original.size();
        if(len != m*n) return {};
        vector<vector<int>> result(m);

        for(int i=0;i<m;i++){
            result[i].assign(original.begin()+i*n, original.begin()+(i+1)*n);
        }   

        return result;
    }
};
