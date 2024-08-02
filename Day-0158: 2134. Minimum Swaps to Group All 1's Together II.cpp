// 2134. Minimum Swaps to Group All 1's Together II (MEDIUM)
// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/?envType=daily-question&envId=2024-08-02


class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int one = count(nums.begin(), nums.end(), 1);
        if(one == 0) return 0;

        vector<int> vec(nums.begin(), nums.end());
        vec.insert(vec.end(), nums.begin(), nums.end());

        int zero = count(vec.begin(), vec.begin() + one, 0);
        int to_change = zero;

        for(int i=one;i<vec.size();i++){
            if(vec[i] == 0) zero++;
            if(vec[i-one] == 0) zero--;

            to_change = min(to_change, zero);
        }

        return to_change;
    }
};
