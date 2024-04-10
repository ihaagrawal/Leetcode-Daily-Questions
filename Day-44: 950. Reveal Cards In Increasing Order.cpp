// 950. Reveal Cards In Increasing Order (MEDIUM)
// https://leetcode.com/problems/reveal-cards-in-increasing-order/description/?envType=daily-question&envId=2024-04-10

//Approach-1 (Space: O(n), Time: O(nlogn))
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        sort(deck.begin(), deck.end());
        vector<int> result(n,0);
        int i=0, j=0;
        bool skip=false;
        while(i<n){
            if(result[j]==0){
                if(skip==false){
                    result[j]=deck[i];
                    i++;
                }
                skip = !skip;
            }
            j=(j+1)%n;
        }
        return result;
    }
};


//Approach-2 (Space: O(n), Time: O(nlogn))
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        sort(deck.begin(), deck.end());
        vector<int> result(n,0);
        queue<int> q;
        for(int i=0;i<n;i++) q.push(i);
        for(int i=0;i<n;i++){
            int ind=q.front();
            q.pop();
            result[ind]=deck[i];
            if(!q.empty()){
                q.push(q.front());
                q.pop();
            }
        }
        return result;
    }
};

