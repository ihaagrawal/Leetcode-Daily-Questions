// 506. Relative Ranks (MEDIUM)
// https://leetcode.com/problems/relative-ranks/description/?envType=daily-question&envId=2024-05-08


class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& scores) {
        int n = scores.size();
        vector<string> result(n);

        // Create a map to store the index of each score
        unordered_map<int, int> scoreIndexMap;
        for (int i = 0; i < n; i++) {
            scoreIndexMap[scores[i]] = i;
        }

        // Sort the scores in descending order
        sort(scores.begin(), scores.end(), greater<int>());

        // Assign ranks
        for (int i = 0; i < n; i++) {
            int rank = i + 1;
            if (rank == 1) {
                result[scoreIndexMap[scores[i]]] = "Gold Medal";
            } else if (rank == 2) {
                result[scoreIndexMap[scores[i]]] = "Silver Medal";
            } else if (rank == 3) {
                result[scoreIndexMap[scores[i]]] = "Bronze Medal";
            } else {
                result[scoreIndexMap[scores[i]]] = to_string(rank);
            }
        }

        return result;
    }
};
