// 85. Maximal Rectangle (HARD)
// https://leetcode.com/problems/maximal-rectangle/description/?source=submission-noac

class Solution {
public:

    int maxArea(vector<int>& nums){
        int n=nums.size(), j, k;
        int max_area=0;
        for(int i=0;i<n;i++){
            j=i-1,k=i+1;
            while(j>=0 && nums[i]<=nums[j]) j--;
            while(k<n && nums[i]<=nums[k]) k++;
            int length=k-j-1;
            max_area=max(length * nums[i], max_area);
        }
        return max_area;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows=matrix.size(), cols=matrix[0].size(), max_area=0;
        vector<int> hist(cols, 0);
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                hist[j] = (matrix[i][j] == '1') ? hist[j] + 1 : 0;
            }
            max_area = max(max_area, maxArea(hist));
        }
        return max_area;
    }
};
