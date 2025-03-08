// 2379. Minimum Recolors to Get K Consecutive Black Blocks (EASY)
// https://leetcode.com/problems/minimum-recolors-to-get-k-consecutive-black-blocks/description/?envType=daily-question&envId=2025-03-08


class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int countB = 0;
        int minRecolors = k; 

        for (int i = 0; i < n; i++) {
            if (blocks[i] == 'B') countB++;
            if (i >= k) if (blocks[i - k] == 'B') countB--;
            if (i >= k - 1) minRecolors = min(minRecolors, k - countB);
        }

        return minRecolors;
    }
};
