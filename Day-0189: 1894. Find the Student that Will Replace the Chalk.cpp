// 1894. Find the Student that Will Replace the Chalk (MEDIUM)
// https://leetcode.com/problems/find-the-student-that-will-replace-the-chalk/description/?envType=daily-question&envId=2024-09-02


class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long totalChalk = 0;
        for (int c : chalk) totalChalk += c;
        k %= totalChalk;
        
        for (int i = 0; i < chalk.size(); ++i) {
            if (chalk[i] > k) return i;
            k -= chalk[i];
        }
        
        return -1; 
    }
};
