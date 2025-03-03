// 2161. Partition Array According to Given Pivot (MEDIUM)
// https://leetcode.com/problems/partition-array-according-to-given-pivot/description/?envType=daily-question&envId=2025-03-03

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int count = 0;
        vector<int> result;
        
        for(int i=0;i<n;i++){
            if(nums[i] < pivot) result.push_back(nums[i]);
            else if(nums[i] == pivot) count++;
        }

        while(count != 0){
            result.push_back(pivot);
            count--;
        }   

        for(int i=0;i<n;i++){
            if(nums[i] > pivot) result.push_back(nums[i]);
        }

        return result;
    }
};
