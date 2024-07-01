// 1550. Three Consecutive Odds (EASY)
// https://leetcode.com/problems/three-consecutive-odds/description/?envType=daily-question&envId=2024-07-01

class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size(), count = 0;
        for(int i=0;i<n;i++){
            if(arr[i] % 2 == 1) count++;
            else count = 0;

            if(count >= 3) return true;
        }
        return false;
    }
};
