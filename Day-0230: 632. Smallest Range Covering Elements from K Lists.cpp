// 632. Smallest Range Covering Elements from K Lists (HARD)
// https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/?envType=daily-question&envId=2024-10-13


class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<int> result(2, 0);
        int n = nums.size();

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int mini, maxi = INT_MIN;

        for(int i=0;i<n;i++){
            pq.push({nums[i][0], {i, 0}});
            maxi = max(maxi, nums[i][0]);
        }

        mini = pq.top().first;
        result[0] = mini;
        result[1] = maxi;

        pair<int, pair<int, int>> temp;
        int col, row, ele;

        while(pq.size() == n){
            temp = pq.top();
            pq.pop();

            ele = temp.first;
            row = temp.second.first;
            col = temp.second.second;

            if(col + 1 < nums[row].size()){
                col++;
                pq.push({nums[row][col], {row, col}});
                maxi = max(maxi, nums[row][col]);
                mini = pq.top().first;

                if(maxi - mini < result[1] - result[0]){
                    result[0] = mini;
                    result[1] = maxi;
                }
            }
        }

        return result;
    }
};
