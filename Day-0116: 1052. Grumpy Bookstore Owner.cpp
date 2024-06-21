// 1052. Grumpy Bookstore Owner (MEDIUM)
// https://leetcode.com/problems/grumpy-bookstore-owner/description/?envType=daily-question&envId=2024-06-21

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = grumpy.size();
        int total = 0;

        for(int i=0;i<n;i++){
            if(grumpy[i] == 0) total += customers[i];
        }

        int result = 0, current = 0;
        for(int i=0;i<n;i++){
            if(grumpy[i] == 1) current += customers[i];

            if(i >= minutes){
                if(grumpy[i - minutes] == 1) current -= customers[i - minutes];
            }

            result = max(current, result);
        }

        return total + result;

    }
};
