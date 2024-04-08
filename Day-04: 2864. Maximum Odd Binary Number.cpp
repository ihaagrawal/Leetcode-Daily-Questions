// 2864. Maximum Odd Binary Number (EASY)
// https://leetcode.com/problems/maximum-odd-binary-number/description/?envType=daily-question&envId=2024-03-01

class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int i,j=0,k,count=0;
        for(i=0;i<s.length();i++)
            {
                if(s[i]=='1')
                    count++;
            }
        if(count<1) 
            return s;
        else
            {
                for(i=0;i<s.length();i++)
                    {   
                        if(s[i]=='1')
                            swap(s[i], s[s.length()-1]);
                    }
                for(i=0;i<s.length()-1;i++)
                    {
                        if(s[i]=='1')
                            {
                                swap(s[j],s[i]);
                                j++;
                            }
                    }
            }
        return s;
    }
};
