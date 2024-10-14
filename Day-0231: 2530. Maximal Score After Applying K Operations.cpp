// 2530. Maximal Score After Applying K Operations (MEDIUM)
// https://leetcode.com/problems/maximal-score-after-applying-k-operations/description/?envType=daily-question&envId=2024-10-14

class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        long long sum = 0;
        priority_queue<int> pq;

        for(int i=0;i<n;i++) pq.push(nums[i]);

        while(k--){
            int ele = pq.top();
            pq.pop();

            sum += ele;
            ele = ceil((double)ele/3);
            pq.push(ele);
        }

        return sum;
    }
};
