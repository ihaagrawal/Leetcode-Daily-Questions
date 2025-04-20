// 781. Rabbits in Forest (MEDIUM)
// https://leetcode.com/problems/rabbits-in-forest/description/?envType=daily-question&envId=2025-04-20

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> count;
        int totalRabbits = 0;

        for (int answer : answers) count[answer]++;

        for (auto& [x, cnt] : count) {
            int groupSize = x + 1;
            int groups = ceil((double)cnt / groupSize);
            totalRabbits += groups * groupSize;
        }

        return totalRabbits;

    }
};
