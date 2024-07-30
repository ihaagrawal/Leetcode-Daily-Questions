// 1653. Minimum Deletions to Make String Balanced (MEDIUM)
// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/?envType=daily-question&envId=2024-07-30


class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length(), count = 0, result = 0;
        for(int i=0;i<n;i++){
            if(s[i] == 'b') count++;
            else result = min(result+1, count);
        }
        return result;
    }
};
