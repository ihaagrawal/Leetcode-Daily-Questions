// 2490. Circular Sentence (EASY)
// // https://leetcode.com/problems/circular-sentence/description/?envType=daily-question&envId=2024-11-02


class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        char start = '\0', end = '\0';

        if(sentence[0] != sentence[n-1]) return false;

        stringstream iss(sentence);
        string word;

        while(iss >> word){
            int m = word.size();
            if(end == '\0'){
                end = word[m-1];
                continue;
            } 

            if(word[0] != end) return false;
            end = word[m-1];
        }

        return true;
    }
};
