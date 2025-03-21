// 2115. Find All Possible Recipes from Given Supplies (MEDIUM)
// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/?envType=daily-question&envId=2025-03-21

class Solution {
public:
    vector<string> findAllRecipes(vector<string>& r, vector<vector<string>>& ing, vector<string>& s) {
        unordered_map<string, int> inDeg;
        unordered_map<string, vector<string>> g;
        unordered_set<string> sup(s.begin(), s.end());
        queue<string> q;
        vector<string> res;

        for (int i = 0; i < r.size(); ++i) {
            for (const string& x : ing[i]) {
                if (!sup.count(x)) {
                    g[x].push_back(r[i]);
                    inDeg[r[i]]++;
                }
            }
        }

        for (const string& x : r) {
            if (inDeg[x] == 0) q.push(x);
        }

        while (!q.empty()) {
            string cur = q.front();
            q.pop();
            res.push_back(cur);

            for (const string& x : g[cur]) {
                if (--inDeg[x] == 0) q.push(x);
            }
        }

        return res;
    }
};
