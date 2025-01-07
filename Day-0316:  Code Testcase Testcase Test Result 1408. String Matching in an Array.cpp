// 1408. String Matching in an Array (EASY)
// https://leetcode.com/problems/string-matching-in-an-array/description/?envType=daily-question&envId=2025-01-07


class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();
        set<string> result;

        for(int i=0;i<n;i++){
            string str = words[i];
            for(int j=0;j<n;j++){
                if(j != i){
                    if(words[j].find(str) != string::npos) result.insert(str);
                }
            }
        }

        return vector<string>(result.begin(), result.end());
    }
};
