// 1002. Find Common Characters (EASY)
// https://leetcode.com/problems/find-common-characters/description/?envType=daily-question&envId=2024-06-05


class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> commonCount(26, INT_MAX);
        
        for (auto& word : words) {
            vector<int> count(26, 0);
            for (char c : word) {
                count[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                commonCount[i] = min(commonCount[i], count[i]);
            }
        }
        
        vector<string> result;
        for (int i = 0; i < 26; i++) {
            while (commonCount[i] > 0) {
                result.push_back(string(1, i + 'a'));
                commonCount[i]--;
            }
        }
        
        return result;
    }
};
