// 1497. Check If Array Pairs Are Divisible by k (MEDIUM)
// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/description/?envType=daily-question&envId=2024-10-01


class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> freq(k);
        int count = 0;

        for(int i=0;i<n;i++){
            int rem = arr[i] % k;
            if(rem < 0) rem += k;
            freq[rem]++;
        }

        if(freq[0] % 2 != 0) return false;
        for(int i=1;i<=k/2;i++){
            if(freq[i] != freq[k-i]) return false;
        }
        return true;;
    }
};
