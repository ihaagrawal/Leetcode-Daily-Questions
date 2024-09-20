// 214. Shortest Palindrome (HARD)
// https://leetcode.com/problems/shortest-palindrome/description/?envType=daily-question&envId=2024-09-20

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string temp = s + "$" + rev;

        vector<int> lps(temp.length(), 0);
        int n = temp.length(), len = 0, i = 1;
        while(i < n){
            if(temp[i] == temp[len]) lps[i++] = ++len;
            else if(len > 0) len = lps[len - 1];
            else i++;
        }

        string result = s.substr(lps.back());
        reverse(result.begin(), result.end());

        return result + s;
    }
};
