// 2799. Count Complete Subarrays in an Array (MEDIUM)
// https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/?envType=daily-question&envId=2025-04-24

class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        unordered_set<int> distinctElements(nums.begin(), nums.end());
        int totalDistinct = distinctElements.size();

        unordered_map<int, int> freqMap;
        int left = 0, result = 0;

        for (int right = 0; right < nums.size(); ++right) {
            freqMap[nums[right]]++;
            while (freqMap.size() == totalDistinct) {
                result += (nums.size() - right);
                freqMap[nums[left]]--;
                if (freqMap[nums[left]] == 0) {
                    freqMap.erase(nums[left]);
                }
                left++;
            }
        }

        return result;
    }
};
