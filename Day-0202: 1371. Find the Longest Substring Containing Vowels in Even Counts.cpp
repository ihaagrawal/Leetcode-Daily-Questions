// 1371. Find the Longest Substring Containing Vowels in Even Counts (MEDIUM)
// https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/?envType=daily-question&envId=2024-09-15

class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size(), max_count = 0, bitmask = 0;
        map<int, int> mp;
        mp[0] = -1;

        for(int i=0;i<n;i++){
            if(s[i] == 'a') bitmask ^= (1 << 0);
            if(s[i] == 'e') bitmask ^= (1 << 1);
            if(s[i] == 'i') bitmask ^= (1 << 2);
            if(s[i] == 'o') bitmask ^= (1 << 3);
            if(s[i] == 'u') bitmask ^= (1 << 4);

            if(mp.find(bitmask) != mp.end()) max_count = max(max_count, i - mp[bitmask]);
            else mp[bitmask] = i;
        }

        return max_count;
    }
};
