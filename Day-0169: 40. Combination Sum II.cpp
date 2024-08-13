// 40. Combination Sum II (MEDIUM)
// https://leetcode.com/problems/combination-sum-ii/description/?envType=daily-question&envId=2024-08-13

class Solution {
public:

    vector<vector<int>> result;

    void check(int n, int curr, int sum, vector<int>& candidates, int target, vector<int> temp){
            if(sum == target){
                result.push_back(temp);
                return;
            }

            if(sum > target || curr >= n) return;

            for(int i=curr;i<n;i++){
                if(i != curr && candidates[i] == candidates[i-1]) continue;
                sum += candidates[i];
                temp.push_back(candidates[i]);
                check(n, i+1, sum, candidates, target, temp);
                sum -= candidates[i];
                temp.pop_back();
            }
        }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        check(n, 0, 0, candidates, target, temp);
        return result;
    }
};
