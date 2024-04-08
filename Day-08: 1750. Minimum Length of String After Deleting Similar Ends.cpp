// 1750. Minimum Length of String After Deleting Similar Ends (MEDIUM)
// https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/?envType=daily-question&envId=2024-03-05

class Solution {
public:
    int minimumLength(string s) {
        int i=0, j=s.length()-1, count=s.length();
        if(count==1)
            return 1;
        while(i<j && s[i]==s[j])
            {   char c=s[i];
                while(i<=j && s[i]==c)
                    {
                        i++;
                        count--;
                    }
                while(i<=j && s[j]==c)
                    {
                        j--;
                        count--;
                    }
            }
        return count;
    }
};
