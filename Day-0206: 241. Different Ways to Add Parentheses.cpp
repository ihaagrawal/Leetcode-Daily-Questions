// 241. Different Ways to Add Parentheses (MEDIUM)
// https://leetcode.com/problems/different-ways-to-add-parentheses/description/?envType=daily-question&envId=2024-09-19

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        vector<int> result;
        for(int i=0;i<n;i++){
            char exp = expression[i];
            if(exp == '+' || exp == '-' || exp == '*'){
                vector<int> str1 = diffWaysToCompute(expression.substr(0, i));
                vector<int> str2 = diffWaysToCompute(expression.substr(i + 1));

                for(int s : str1){
                    for(int t : str2){
                        if(exp == '+') result.push_back(s + t);
                        else if(exp == '-') result.push_back(s - t);
                        else if(exp == '*') result.push_back(s * t);
                    }
                }
            }
        }

        if(result.empty()) result.push_back(stoi(expression));
        return result;
    }
};
