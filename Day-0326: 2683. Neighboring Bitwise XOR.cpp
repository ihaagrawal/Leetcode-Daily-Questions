// 2683. Neighboring Bitwise XOR (MEDIUM)
// https://leetcode.com/problems/neighboring-bitwise-xor/?envType=daily-question&envId=2025-01-17

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();

        bool isValidCase0 = true;
        int prev = 0;
        for (int i = 0; i < n; ++i) {
            int current = derived[i] ^ prev;
            if (i == n - 1 && current != 0) {
                isValidCase0 = false;
                break;
            }
            prev = current;
        }

        bool isValidCase1 = true;
        prev = 1;
        for (int i = 0; i < n; ++i) {
            int current = derived[i] ^ prev;
            if (i == n - 1 && current != 1) {
                isValidCase1 = false;
                break;
            }
            prev = current;
        }

        return isValidCase0 || isValidCase1;
    }
};
