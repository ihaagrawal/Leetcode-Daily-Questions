// 3163. String Compression III (MEDIUM)
// https://leetcode.com/problems/string-compression-iii/description/?envType=daily-question&envId=2024-11-04


class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int count = 1, n = word.size();
        char ch = word[0];

        for(int i=1;i<n;i++){
            if(word[i] == ch && count < 9) count++;
            else{
                comp.push_back(count + '0');
                comp.push_back(ch);
                ch = word[i];
                count = 1;
            }
        }

        comp.push_back(count + '0');
        comp.push_back(ch);
        return comp;
    }
};
