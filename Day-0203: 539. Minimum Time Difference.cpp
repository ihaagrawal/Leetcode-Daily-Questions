// 539. Minimum Time Difference (MEDIUM)
// https://leetcode.com/problems/minimum-time-difference/description/?envType=daily-question&envId=2024-09-16

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> timeInMinutes(timePoints.size());
        
        for (int i = 0; i < timePoints.size(); ++i) {
            int hours = stoi(timePoints[i].substr(0, 2));
            int minutes = stoi(timePoints[i].substr(3));
            timeInMinutes[i] = hours * 60 + minutes;
        }

        sort(timeInMinutes.begin(), timeInMinutes.end());

        int minTimeDifference = INT_MAX;
        for (int i = 0; i < timeInMinutes.size() - 1; ++i) {
            minTimeDifference = min(minTimeDifference, timeInMinutes[i + 1] - timeInMinutes[i]);
        }

        minTimeDifference = min(minTimeDifference, 24 * 60 - timeInMinutes.back() + timeInMinutes.front());
        return minTimeDifference;
    }
};
