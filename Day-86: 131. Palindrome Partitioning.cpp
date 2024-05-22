// 131. Palindrome Partitioning (MEDIUM)
// https://leetcode.com/problems/palindrome-partitioning/description/?envType=daily-question&envId=2024-05-22

class Solution {
public:

    void part(string& s, int ind, vector<string>& path, vector<vector<string>>& result){
        if(ind == s.size()){
            result.push_back(path);
            return;
        }

        for(int i=ind;i<s.size();i++){
            if(isPalindrome(s, ind, i)){
                path.push_back(s.substr(ind, i-ind+1));
                part(s, i+1, path, result);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(string& s,  int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        part(s, 0, path, result);
        return result;
    }
};
