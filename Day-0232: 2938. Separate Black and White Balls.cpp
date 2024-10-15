// 2938. Separate Black and White Balls (MEDIUM)
// https://leetcode.com/problems/separate-black-and-white-balls/description/?envType=daily-question&envId=2024-10-15

class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();
        long long count = 0, result = 0;

        for(int i=0;i<n;i++){
            if(s[i] == '1') count++;
            else result += count;
        }

        return result;
    }
};
