// 1208. Get Equal Substrings Within Budget (MEDIUM)
// https://leetcode.com/problems/get-equal-substrings-within-budget/description/?envType=daily-question&envId=2024-05-28

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int result=0, left=0, right=0, cost=0;

        while(right<s.length()){
            cost += abs(s[right] - t[right]);

            while(cost > maxCost && left < right){
                cost -= abs(s[left]-t[left]);
                left ++;
            }

            if(cost <= maxCost){
                result = max(result, right-left+1);
            }

            right++;
        }

        return result;
    }
};
