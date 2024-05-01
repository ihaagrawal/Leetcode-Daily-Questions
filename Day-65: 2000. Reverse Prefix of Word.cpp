// 2000. Reverse Prefix of Word (EASY)
// https://leetcode.com/problems/reverse-prefix-of-word/description/?envType=daily-question&envId=2024-05-01

class Solution {
public:
    string reversePrefix(string word, char ch) {
        int n=word.length();
        for(int i=0;i<n;i++){
            if(word[i]==ch){
                reverse(word.begin(), word.begin() + i +1);
                return word;
            }
        }
        return word;
    }
};
