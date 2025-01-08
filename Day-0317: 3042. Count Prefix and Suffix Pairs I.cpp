// 3042. Count Prefix and Suffix Pairs I (EASY)
// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i/description/?envType=daily-question&envId=2025-01-08


class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            string str = words[i];
            int m = str.size();
            for (int j = i + 1; j < n; j++) {
                string second = words[j];
                int len = second.size();
                
                int k, l;
                for (k = 0; k < min(m, len); k++) {
                    if (str[k] != second[k]) break;
                }
                if (k == m) count++;
                else continue;

                for (k = m - 1, l = len - 1; k >= 0 && l >= 0; k--, l--) {
                    if (str[k] != second[l]) break;
                }
                if (k < 0) continue;
                else count--;
            }
        }

        return count;
    }
};
