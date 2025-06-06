// 1079. Letter Tile Possibilities (MEDIUM)
// https://leetcode.com/problems/letter-tile-possibilities/description/?envType=daily-question&envId=2025-02-17


class Solution {
public:
    int count=0;
    void helper(string nums, int start){
        count++;
        for(int i=start;i<nums.size();i++){
            if(i==start || nums[start]!=nums[i]){
                swap(nums[start],nums[i]);
                helper(nums,start+1);
            }
        }
        return ;
    }
    int numTilePossibilities(string tiles) {
        int start=0;
        sort(tiles.begin(), tiles.end());
        helper(tiles,start);
        return count-1;
    }
};
