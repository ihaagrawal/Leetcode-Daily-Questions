// 3169. Count Days Without Meetings (MEDIUM)
// https://leetcode.com/problems/count-days-without-meetings/description/?envType=daily-question&envId=2025-03-24

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        int n = meetings.size();
        int meetingDays = 0;

        sort(meetings.begin(), meetings.end());
        vector<vector<int>> mergedMeetings;
        mergedMeetings.push_back(meetings[0]);

        for (int i = 1; i < n; ++i) {
            auto& lastMerged = mergedMeetings.back();

            if (lastMerged[1] >= meetings[i][0]) {
                lastMerged[1] = max(lastMerged[1], meetings[i][1]);
            } else {
                mergedMeetings.push_back(meetings[i]);
            }
        }

        for (const auto& it : mergedMeetings) {
            meetingDays += (it[1] - it[0] + 1);
        }

        return abs(days - meetingDays);
    }
};
