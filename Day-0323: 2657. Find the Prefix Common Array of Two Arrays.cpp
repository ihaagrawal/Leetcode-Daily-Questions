// 2657. Find the Prefix Common Array of Two Arrays (MEDIUM)
// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/?envType=daily-question&envId=2025-01-14


class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> C(n, 0);
        unordered_set<int> seen;
        int commonCount = 0;

        for (int i = 0; i < n; ++i) {
            if (seen.count(A[i])) ++commonCount;
            else seen.insert(A[i]);

            if (seen.count(B[i])) ++commonCount;
            else seen.insert(B[i]);

            C[i] = commonCount;
        }

        return C;
    }
};
