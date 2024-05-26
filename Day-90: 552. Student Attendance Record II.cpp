// 552. Student Attendance Record II (HARD)
// https://leetcode.com/problems/student-attendance-record-ii/description/?envType=daily-question&envId=2024-05-26

class Solution {
public:

    int mod = 1e9+7;
    long dp[100002][2][3];

    int solve(int idx, int n, bool absent_taken, int late){
        if(idx >= n) return 1;
        if(dp[idx][absent_taken][late] != -1) return dp[idx][absent_taken][late];

        long present = solve(idx+1, n, absent_taken, 0);

        long new_late = 0;
        if(late != 2){
            new_late = solve(idx+1, n, absent_taken, late+1);
        }

        long absent = 0;
        if(!absent_taken){
            absent = solve(idx+1, n, true, 0);
        }

        return dp[idx][absent_taken][late] = max(dp[idx][absent_taken][late], (present%mod + new_late%mod + absent%mod)%mod);

    }

    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0, n, false, 0);
    }
};
