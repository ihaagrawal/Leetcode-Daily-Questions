// 2071. Maximum Number of Tasks You Can Assign (HARD)
// https://leetcode.com/problems/maximum-number-of-tasks-you-can-assign/description/?envType=daily-question&envId=2025-05-01

class Solution {
public:
    bool canCompleteTasks(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> workerSet(workers.end() - k, workers.end());
        
        for (int i = k - 1; i >= 0; --i) {
            int task = tasks[i];
            
            auto it = workerSet.upper_bound(task - 1);
            if (it != workerSet.end()) {
                workerSet.erase(it);
                continue;
            }
            
            if (pills > 0) {
                it = workerSet.lower_bound(task - strength);
                if (it != workerSet.end()) {
                    workerSet.erase(it);
                    pills--;
                    continue;
                }
            }
            
            return false;
        }
        
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        
        int left = 0, right = min((int)tasks.size(), (int)workers.size());
        int result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canCompleteTasks(mid, tasks, workers, pills, strength)) {
                result = mid; 
                left = mid + 1; 
            } else {
                right = mid - 1; 
            }
        }
        
        return result;
    }
};
