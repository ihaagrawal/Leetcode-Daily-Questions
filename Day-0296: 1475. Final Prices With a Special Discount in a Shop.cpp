// 1475. Final Prices With a Special Discount in a Shop (EASY)
// https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/description/?envType=daily-question&envId=2024-12-18


class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> answer(n);
        stack<int> st;
        
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && prices[i] <= prices[st.top()]) {
                int idx = st.top();
                st.pop();
                answer[idx] = prices[idx] - prices[i];
            }
            st.push(i);
        }
        
        while (!st.empty()) {
            int idx = st.top();
            st.pop();
            answer[idx] = prices[idx];
        }
        
        return answer;
    }
};
