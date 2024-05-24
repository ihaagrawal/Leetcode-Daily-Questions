// 1255. Maximum Score Words Formed by Letters (HARD)
// https://leetcode.com/problems/maximum-score-words-formed-by-letters/?envType=daily-question&envId=2024-05-24

class Solution {
public:

    int solve(vector<string>& words, vector<int>& freq, vector<int>& score, int ind){
        if(ind == words.size()) return 0;

        int score_no = solve(words, freq, score, ind+1);

        int score_word = 0;
        string word = words[ind];
        bool flag = true;

        for(int i=0;i<word.length();i++){
            char ch = word[i];

            if(freq[ch-'a']==0){
                flag = false;
            }

            freq[ch-'a']--;
            score_word += score[ch-'a'];
        }

        int score_yes = 0;
        if(flag==true){
            score_yes = score_word + solve(words, freq, score, ind+1);
        }

        for(int i=0;i<word.length();i++){
            char ch = word[i];
            freq[ch - 'a']++;
        }

        return max(score_yes, score_no);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> freq(26, 0);
        for(char ch : letters){
            freq[ch - 'a']++;
        }

        return solve(words, freq, score, 0);
    }
};
