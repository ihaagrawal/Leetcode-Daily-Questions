// 2131. Longest Palindrome by Concatenating Two Letter Words (MEDIUM)
// https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/description/?envType=daily-question&envId=2025-05-25

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> count;
        int result = 0;
        bool hasCentral = false;

        for (const string& word : words) count[word]++;

        for (auto& [word, freq] : count) {
            string reversedWord = string(word.rbegin(), word.rend());
            
            if (word == reversedWord) {
                result += (freq / 2) * 4;
                if (freq % 2 == 1) hasCentral = true;
            } else if (count.find(reversedWord) != count.end()) {
                int pairs = min(freq, count[reversedWord]);
                result += pairs * 4;
                count[reversedWord] -= pairs;
                count[word] -= pairs;
            }
        }

        if (hasCentral) result += 2;
        return result;
    }
};
