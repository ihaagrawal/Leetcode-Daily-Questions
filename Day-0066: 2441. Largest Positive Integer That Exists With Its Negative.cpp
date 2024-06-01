// 2441. Largest Positive Integer That Exists With Its Negative (EASY)
// https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/?envType=daily-question&envId=2024-05-02

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }

        while(!st.empty()){
            auto it=st.begin();
            int num=*it;
            if(st.find(num*(-1))!=st.end()){
                return num*(-1);
            }
            st.erase(it);
        }
        return -1;
    }

};
