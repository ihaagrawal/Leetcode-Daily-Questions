// 2070. Most Beautiful Item for Each Query (MEDIUM)
// https://leetcode.com/problems/most-beautiful-item-for-each-query/description/?envType=daily-question&envId=2024-11-12


class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end());

        map<int, int> beautyMap;
        int maxB = 0;

        for (auto& item : items) {
            int p = item[0], b = item[1];
            maxB = max(maxB, b);
            beautyMap[p] = maxB;
        }

        vector<int> res;
        for (int q : queries) {
            auto it = beautyMap.upper_bound(q);
            if (it == beautyMap.begin()) {
                res.push_back(0);
            } else {
                --it;
                res.push_back(it->second);
            }
        }

        return res;
    }
};
