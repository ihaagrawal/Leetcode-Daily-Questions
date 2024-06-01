// 1442. Count Triplets That Can Form Two Arrays of Equal XOR (MEDIUM)
// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/?envType=daily-question&envId=2024-05-30


class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        for(int i=0;i<n;i++){
            int val = arr[i];
            for(int k=i+1;k<n;k++){
                val ^= arr[k];

                if(val == 0){
                    count += (k-i);
                }
            }
        }

        return count;
    }
};
