// 2381. Shifting Letters II (MEDIUM)
// https://leetcode.com/problems/shifting-letters-ii/description/?envType=daily-question&envId=2025-01-05


class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> netShifts(s.size() + 1, 0);

        for (const auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int direction = shift[2];

            netShifts[start] += (direction == 1 ? 1 : -1);
            netShifts[end + 1] -= (direction == 1 ? 1 : -1);
        }

        int currentShift = 0;
        for (int i = 0; i < s.size(); ++i) {
            currentShift += netShifts[i];
            s[i] = 'a' + (s[i] - 'a' + currentShift % 26 + 26) % 26;
        }

        return s;
    }
};
