// 846. Hand of Straights (MEDIUM)
// https://leetcode.com/problems/hand-of-straights/description/?envType=daily-question&envId=2024-06-06


class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n % groupSize != 0) return false;

        sort(hand.begin(), hand.end());

        int last = -1, count = 0;

        for(int i=0;i<n;i++){
            if(hand[i] == -1) continue;
            last = hand[i];
            count = 1;
            vector<int> index = {i};

            for(int j=0;j<n;j++){
                if(j == i) continue;
                if(count == groupSize) break;

                if(hand[j] == last + 1){
                    count++;
                    index.push_back(j);
                    last = hand[j];
                }
            }

            if(count < groupSize) return false; 
            else{
                for(int k=0;k<groupSize;k++){
                    hand[index[k]] = -1;
                }
            }
        }

        return true;
    }
};
