// 2073. Time Needed to Buy Tickets (EASY)
// https://leetcode.com/problems/time-needed-to-buy-tickets/description/?envType=daily-question&envId=2024-04-09

class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int n=tickets.size(), sec=0, i=0;
        int value=tickets[k];
        while(value>0){
            if(i==n) i=0;
            else if(i!=k){
                if(tickets[i]!=0){
                    tickets[i]--;
                    sec++;
                }
                i++;
            }
            else if(i==k){
                if(value==0) break;
                value--;
                i++;
                sec++;
            }
        }
        return sec;
    }
};
