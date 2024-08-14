// 719. Find K-th Smallest Pair Distance (HARD)
// https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/?envType=daily-question&envId=2024-08-14


class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dist;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                dist.push_back(abs(nums[i] - nums[j]));
            }
        }
        nth_element(dist.begin(), dist.begin()+(k-1), dist.end());
        return dist[k-1];
    }
};
