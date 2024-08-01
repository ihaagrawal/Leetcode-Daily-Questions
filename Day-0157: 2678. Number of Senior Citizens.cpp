// 2678. Number of Senior Citizens (EASY)
// https://leetcode.com/problems/number-of-senior-citizens/description/?envType=daily-question&envId=2024-08-01


class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0;
        for(string word : details){
            int n = word.size();
            int age = 0;
            age = age * 10 + (word[n-4] - '0');
            age = age * 10 + (word[n-3] - '0');

            if(age > 60) count++;
        }

        return count;
    }
};
