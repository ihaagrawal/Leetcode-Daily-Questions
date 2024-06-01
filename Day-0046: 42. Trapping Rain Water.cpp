// 42. Trapping Rain Water (HARD)
// https://leetcode.com/problems/trapping-rain-water/description/?envType=daily-question&envId=2024-04-12

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(), result = 0;
        vector<int> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && height[i] > height[st.back()]) {
                int mid = height[st.back()];
                st.pop_back();
                if (st.empty()) break;
                int low = height[st.back()];
                result += (i - st.back() - 1) * (min(height[i], low) - mid);
            }
            st.push_back(i);
        }
        return result;
    }
};
