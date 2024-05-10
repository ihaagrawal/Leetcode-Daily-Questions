// 786. K-th Smallest Prime Fraction (MEDIUM)
// https://leetcode.com/problems/k-th-smallest-prime-fraction/description/?envType=daily-question&envId=2024-05-10


class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size(), i=0, j=n-1 ,count=0;
        set<pair<float, pair<int,int>>> st;
        for(i=0;i<n-1;i++){
            for(j=n-1;j>i;j--){
                st.insert({static_cast<float>(arr[i])/arr[j], {i, j}});
            }
        }
        
        auto it = next(st.begin(), k-1);
        return {arr[it->second.first], arr[it->second.second]};
    }
};
