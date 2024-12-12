// 2558. Take Gifts From the Richest Pile (EASY)
// https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/?envType=daily-question&envId=2024-12-12


class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> maxHeap(gifts.begin(), gifts.end());
        
        while (k-- > 0) {
            int top = maxHeap.top();
            maxHeap.pop();
            maxHeap.push(floor(sqrt(top)));
        }
        
        long long totalGifts = 0;
        while (!maxHeap.empty()) {
            totalGifts += maxHeap.top();
            maxHeap.pop();
        }
        
        return totalGifts;
    }
};
