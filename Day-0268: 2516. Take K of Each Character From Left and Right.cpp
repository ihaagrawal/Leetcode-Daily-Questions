// 2516. Take K of Each Character From Left and Right (MEDIUM)
// https://leetcode.com/problems/take-k-of-each-character-from-left-and-right/description/?envType=daily-question&envId=2024-11-20


class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        vector<int> freq(3, 0);
        for(char ch : s) freq[ch - 'a']++;
        if(freq[0] < k || freq[1] < k || freq[2] < k) return -1;

        int minutes = n;
        int i = 0, j = 0;
        while(j < n){
            int ch = s[j] - 'a';
            freq[ch]--;
            while(i <= j && (freq[0] < k || freq[1] < k || freq[2] < k)){
                freq[s[i] - 'a']++;
                i++;
            }
            minutes = min(minutes, n - (j - i + 1));
            j++;
        }

        return minutes;
    }
};
