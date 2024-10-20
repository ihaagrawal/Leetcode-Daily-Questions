// 1106. Parsing A Boolean Expression (HARD)
// https://leetcode.com/problems/parsing-a-boolean-expression/description/?envType=daily-question&envId=2024-10-20


class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;
        
        for (char c : expression) {
            if (c == ',' || c == '(') continue;
            
            if (c == 't' || c == 'f' || c == '!' || c == '&' || c == '|') {
                stk.push(c);
            } else if (c == ')') {
                vector<bool> values;
                while (stk.top() == 't' || stk.top() == 'f') {
                    values.push_back(stk.top() == 't');
                    stk.pop();
                }
                char op = stk.top();
                stk.pop();
                
                bool res;
                if (op == '&') {
                    res = true;
                    for (bool val : values) res &= val;
                } else if (op == '|') {
                    res = false;
                    for (bool val : values) res |= val;
                } else if (op == '!') {
                    res = !values[0];
                }
                stk.push(res ? 't' : 'f');
            }
        }
        
        return stk.top() == 't';
    }
};
