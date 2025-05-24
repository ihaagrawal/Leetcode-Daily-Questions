// 2942. Find Words Containing Character (EASY)
// https://leetcode.com/problems/find-words-containing-character/description/?envType=daily-question&envId=2025-05-24

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        int n=words.size();
        vector<int> result;
        for(int i=0;i<n;i++){
            int found=0;
            for(int j=0;j<words[i].length();j++){
                if(words[i][j]==x){
                    found=1;
                    break;
                }
            }
            if(found==1) result.push_back(i);
        }
        return result;
    }
};
