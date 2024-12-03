// 2109. Adding Spaces to a String (MEDIUM)
// https://leetcode.com/problems/adding-spaces-to-a-string/description/?envType=daily-question&envId=2024-12-03

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string result = "";
        int n = s.size(), m = spaces.size();
        int i = 0, j = 0;

        while(i < n){
            if(j < m && i == spaces[j]){
                result += " ";
                j++;
                continue;
            }else result.push_back(s[i]);
            i++;
        }

        return result;
    }
};
