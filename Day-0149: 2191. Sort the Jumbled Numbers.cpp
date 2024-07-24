// 2191. Sort the Jumbled Numbers (MEDIUM)
// https://leetcode.com/problems/sort-the-jumbled-numbers/description/?envType=daily-question&envId=2024-07-24

class Solution {
public:
    int getMappedNumber(vector<int>& mapping, int num) {
        int mappedNumber = 0;
        int k = 0;
        if (num == 0) return mapping[0];
        else {
            while (num > 0) {
                int unitDigit = num % 10;
                unitDigit = mapping[unitDigit];
                mappedNumber = mappedNumber + (unitDigit * pow(10, k));
                k++;
                num = num / 10;
            }
            return mappedNumber;
        }
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        unordered_map<int, pair<int, int>> mpp;
        int i = 0;
        for (int it : nums) {
            int mappedNumber = getMappedNumber(mapping, it);
            mpp[it] = {mappedNumber, i};
            i++;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (mpp[a].first != mpp[b].first) return mpp[a].first < mpp[b].first;
            else return mpp[a].second < mpp[b].second;
        });

        return nums;
    }
};
