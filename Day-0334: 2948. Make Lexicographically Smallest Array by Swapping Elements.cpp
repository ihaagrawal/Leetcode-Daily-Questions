// 2948. Make Lexicographically Smallest Array by Swapping Elements (MEDIUM)
// https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/description/?envType=daily-question&envId=2025-01-25

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& arr, int t) {
        int n = arr.size();
        vector<pair<int, int>> vp;

        // Create value-index pairs
        for (int i = 0; i < n; ++i) vp.push_back({arr[i], i});
        sort(vp.begin(), vp.end());

        // Group elements by threshold
        vector<vector<pair<int, int>>> groups;
        groups.push_back({vp[0]});

        for (int i = 1; i < n; ++i) {
            if (vp[i].first - vp[i - 1].first <= t) groups.back().push_back(vp[i]);
            else groups.push_back({vp[i]});
        }

        // Process each group
        for (const auto& g : groups) {
            vector<int> idx;
            for (const auto& [val, i] : g) idx.push_back(i);

            // Sort indices and assign values in order
            sort(idx.begin(), idx.end());
            vector<int> vals;
            for (const auto& [val, i] : g)vals.push_back(val);
            for (size_t i = 0; i < idx.size(); ++i) arr[idx[i]] = vals[i];
        }

        return arr;
    }
};
