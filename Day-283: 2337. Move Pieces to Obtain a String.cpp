// 2337. Move Pieces to Obtain a String (MEDIUM)
// https://leetcode.com/problems/move-pieces-to-obtain-a-string/description/?envType=daily-question&envId=2024-12-05


class Solution {
public:
    bool canChange(string start, string target) {
        string sFiltered, tFiltered;
        for (char c : start) if (c != '_') sFiltered += c;
        for (char c : target) if (c != '_') tFiltered += c;
        if (sFiltered != tFiltered) return false;

        int i = 0, j = 0;
        while (i < start.size() && j < target.size()) {
            while (i < start.size() && start[i] == '_') i++;
            while (j < target.size() && target[j] == '_') j++;
            if (i < start.size() && j < target.size()) {
                if (start[i] != target[j]) return false;
                if (start[i] == 'L' && i < j) return false;
                if (start[i] == 'R' && i > j) return false;
                i++;
                j++;
            }
        }
        return true;
    }
};
