// 2570. Merge Two 2D Arrays by Summing Values (EASY)
// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/?envType=daily-question&envId=2025-03-02

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>> result;
        int i = 0, j = 0;
        
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i][0] == nums2[j][0]) {
                result.push_back({nums1[i][0], nums1[i][1] + nums2[j][1]});
                i++;
                j++;
            } else if (nums1[i][0] < nums2[j][0]) {
                result.push_back(nums1[i]);
                i++;
            } else {
                result.push_back(nums2[j]);
                j++;
            }
        }
        
        while (i < nums1.size()) {
            result.push_back(nums1[i]);
            i++;
        }
        
        while (j < nums2.size()) {
            result.push_back(nums2[j]);
            j++;
        }
        
        return result;
    }
};
