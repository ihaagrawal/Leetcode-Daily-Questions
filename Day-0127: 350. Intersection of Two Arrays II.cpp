// 350. Intersection of Two Arrays II (EASY)
// https://leetcode.com/problems/intersection-of-two-arrays-ii/description/?envType=daily-question&envId=2024-07-02


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> result;
        int i=0, j=0;

        while(i < n && j < m){
            if(nums1[i] == nums2[j]){
                result.push_back(nums1[i]);
                i++;
                j++;
            }else if(nums1[i] > nums2[j]) j++;
            else i++;
        }
        return result;
    }
};
