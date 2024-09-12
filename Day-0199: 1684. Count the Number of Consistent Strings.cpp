// 1684. Count the Number of Consistent Strings (EASY)
// https://leetcode.com/problems/count-the-number-of-consistent-strings/description/?envType=daily-question&envId=2024-09-12

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int n = allowed.size(), m = words.size();
        for(auto word : words){
            for(int i=0;i<word.size();i++){
                if(allowed.find(word[i]) == string::npos){
                    m--;
                    break;
                }
            }
        }
        return m;
    }
};
