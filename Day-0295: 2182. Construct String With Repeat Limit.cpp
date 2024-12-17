// 2182. Construct String With Repeat Limit (MEDIUM)
// https://leetcode.com/problems/construct-string-with-repeat-limit/description/?envType=daily-question&envId=2024-12-17


class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for (char c : s) freq[c - 'a']++;
        priority_queue<pair<char, int>> pq;
        for (int i = 0; i < 26; i++) 
            if (freq[i] > 0) pq.push({(char)('a' + i), freq[i]});
        string result;
        while (!pq.empty()) {
            auto [ch, cnt] = pq.top(); pq.pop();
            int use = min(cnt, repeatLimit);
            for (int i = 0; i < use; i++) result += ch;
            if (cnt > use) {
                if (pq.empty()) break;
                auto [ch2, cnt2] = pq.top(); pq.pop();
                result += ch2;
                if (--cnt2 > 0) pq.push({ch2, cnt2});
                pq.push({ch, cnt - use});
            }
        }
        return result;
    }
};
