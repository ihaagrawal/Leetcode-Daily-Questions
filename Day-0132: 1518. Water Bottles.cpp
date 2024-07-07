// 1518. Water Bottles (EASY)
// https://leetcode.com/problems/water-bottles/description/?envType=daily-question&envId=2024-07-07


class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count = 0, empty = 0;
        while(numBottles > 0){
            count += numBottles;
            empty += numBottles;
            numBottles = empty/numExchange;
            empty %= numExchange;
        }
        return count;
    }
};
