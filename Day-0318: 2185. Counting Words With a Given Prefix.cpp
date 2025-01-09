// 2185. Counting Words With a Given Prefix (EASY)
// https://leetcode.com/problems/counting-words-with-a-given-prefix/description/?envType=daily-question&envId=2025-01-09

class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size(), count = 0;
        int len = pref.size();

        for(int i=0;i<n;i++){
            string str = words[i];
            
            int m = str.size();
            if(len > m) continue;

            int j;
            for(j=0;j<len;j++){
                if(str[j] != pref[j]) break;
            }

            if(j < len) continue;
            count++;
        }

        return count;
    }
};
