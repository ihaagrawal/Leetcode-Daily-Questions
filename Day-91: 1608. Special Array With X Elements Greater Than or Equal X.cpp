// 1608. Special Array With X Elements Greater Than or Equal X (EASY)
// https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/?envType=daily-question&envId=2024-05-27

class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        int start = 1, end = n;
        int count;
        while(start<=end){
            count = 0;
            int mid = (start+end)/2;
            for(int i=0;i<n;i++){
                if(count > mid) break;
                if(nums[i] >= mid){
                    count++;
                }
            }

            if(count == mid) return mid;
            else if(count>mid){
                start = mid + 1;
            }else {
                end = mid - 1;
            }
        }

        return -1;
    }
};
