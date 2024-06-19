// 1482. Minimum Number of Days to Make m Bouquets (MEDIUM)
// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/?envType=daily-question&envId=2024-06-19

#include <algorithm>
class Solution {
public:

    bool possible(vector<int>& bloomDay, int m, int k, int mid){
        int num=0, count=0;
        int n=bloomDay.size();
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid)
                count++;
            else{
                num += count/k;
                count=0;
            }
        }
        num += count/k;
        return (num>=m);
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        long long val = m * 1LL * k * 1LL;
        if(val>n) return -1;

        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());

        int low=mini, high=maxi;
        while(low<=high){
            int mid=(low+high)/2;
            if(possible(bloomDay, m, k, mid))
                high=mid-1;
            else
                low=mid+1;
        }
        
        return low;
    }
};
