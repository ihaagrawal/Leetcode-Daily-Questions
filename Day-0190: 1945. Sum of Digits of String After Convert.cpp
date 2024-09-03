// 1945. Sum of Digits of String After Convert (MEDIUM)
// https://leetcode.com/problems/sum-of-digits-of-string-after-convert/description/?envType=daily-question&envId=2024-09-03


#include <string>
#include <iostream>

class Solution {
public:

    long long digitSum(long long num){
        long long sum = 0;
        while(num > 0){
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int getLucky(std::string s, int k) {
        long long num = 0;

        for(char ch : s){
            int numVal = ch - 'a' + 1;
            while (numVal > 0) {
                num += numVal % 10;
                numVal /= 10;
            }
        }
        
        for(int i = 1; i < k; i++){
            num = digitSum(num);
        }

        return static_cast<int>(num);
    }
};
