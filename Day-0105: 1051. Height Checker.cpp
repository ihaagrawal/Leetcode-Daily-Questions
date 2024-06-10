// 1051. Height Checker (EASY)
// https://leetcode.com/problems/height-checker/description/?envType=daily-question&envId=2024-06-10

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int> expected(n);

        for(int i=0;i<n;i++) expected[i] = heights[i];
        sort(expected.begin(), expected.end());

        int count = 0;
        for(int i=0;i<n;i++){
            if(heights[i] != expected[i]) count++;
        }

        return count;
    }
};
