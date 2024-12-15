// 1792. Maximum Average Pass Ratio (MEDIUM)
// https://leetcode.com/problems/maximum-average-pass-ratio/description/?envType=daily-question&envId=2024-12-15


class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        auto gain = [](int pass, int total) {
            return (double)(pass + 1) / (total + 1) - (double)pass / total;
        };

        priority_queue<pair<double, pair<int, int>>> maxHeap;

        for (auto& c : classes) {
            int pass = c[0], total = c[1];
            maxHeap.push({gain(pass, total), {pass, total}});
        }

        while (extraStudents--) {
            auto [currentGain, classData] = maxHeap.top();
            maxHeap.pop();

            int pass = classData.first, total = classData.second;
            pass++;
            total++;
            maxHeap.push({gain(pass, total), {pass, total}});
        }

        double totalRatio = 0.0;
        while (!maxHeap.empty()) {
            auto [_, classData] = maxHeap.top();
            maxHeap.pop();

            int pass = classData.first, total = classData.second;
            totalRatio += (double)pass / total;
        }

        return totalRatio / classes.size();
    }
};
