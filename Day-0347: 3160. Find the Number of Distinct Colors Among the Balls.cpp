// 3160. Find the Number of Distinct Colors Among the Balls (MEDIUM)
// https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/description/?envType=daily-question&envId=2025-02-07


class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballColor; 
        unordered_map<int, int> colorCount; 
        unordered_set<int> distinctColors; 
        vector<int> result;

        for (const auto& query : queries) {
            int ball = query[0];
            int color = query[1];

            if (ballColor.count(ball) > 0) {
                int oldColor = ballColor[ball];
                colorCount[oldColor]--;
                if (colorCount[oldColor] == 0) {
                    distinctColors.erase(oldColor);
                }
            }

            ballColor[ball] = color;
            colorCount[color]++;
            distinctColors.insert(color);

            result.push_back(distinctColors.size());
        }

        return result;
    }
};
