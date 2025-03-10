// 3306. Count of Substrings Containing Every Vowel and K Consonants II (MEDIUM)
// https://leetcode.com/problems/count-of-substrings-containing-every-vowel-and-k-consonants-ii/description/?envType=daily-question&envId=Invalid%20Date

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    long long atLeastK(string& word, int k) {
        int n = word.size();
        long long count = 0;
        int cCnt = 0, l = 0;
        unordered_map<char, int> vMap;

        for (int r = 0; r < n; r++) {
            if (isVowel(word[r])) vMap[word[r]]++;
            else cCnt++;

            while (vMap.size() == 5 && cCnt >= k) {
                count += n - r;
                if (isVowel(word[l])) {
                    if (--vMap[word[l]] == 0) vMap.erase(word[l]);
                } else cCnt--;
                
                l++;
            }
        }

        return count;
    }

    long long countOfSubstrings(string word, int k) {
        return atLeastK(word, k) - atLeastK(word, k + 1);
    }
};
