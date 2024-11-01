// 1957. Delete Characters to Make Fancy String (EASY)
// https://leetcode.com/problems/delete-characters-to-make-fancy-string/description/?envType=daily-question&envId=2024-11-01


class Solution {
public:
    string makeFancyString(string s) {
        string result = "";
        result.push_back(s[0]);
        int n = s.size(), count = 1;

        for(int i=1;i<n;i++){
            if(s[i] == result.back()){
                count++;
                if(count < 3)result.push_back(s[i]);
            }
            else{
                count = 1;
                result.push_back(s[i]);
            }
        }
        return result;
    }
};
