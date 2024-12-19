// 769. Max Chunks To Make Sorted (MEDIUM)
// https://leetcode.com/problems/max-chunks-to-make-sorted/description/?envType=daily-question&envId=2024-12-19


class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxSoFar = 0;
        int chunks = 0;

        for (int i = 0; i < arr.size(); i++) {
            maxSoFar = max(maxSoFar, arr[i]);
            if (maxSoFar == i) chunks++;
        }

        return chunks;
    }
};
