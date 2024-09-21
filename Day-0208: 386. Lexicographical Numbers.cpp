// 386. Lexicographical Numbers (MEDIUM)
// https://leetcode.com/problems/lexicographical-numbers/description/?envType=daily-question&envId=2024-09-21


class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int num = 1;

        for(int i=1;i<=n;i++){
            result.push_back(num);
            if(num * 10 <= n) num = num * 10;
            else{
                while(num % 10 == 9 || num >= n) num = num/10;
                num += 1;
            }
        }

        return result;
    }
};
