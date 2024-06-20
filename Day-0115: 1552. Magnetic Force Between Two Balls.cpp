// 1552. Magnetic Force Between Two Balls (MEDIUM)
// https://leetcode.com/problems/magnetic-force-between-two-balls/description/?envType=daily-question&envId=2024-06-20


class Solution {
public:

    bool canPlace(vector<int>& position, int dist, int balls){
        int count = 1, lastPlaced = position[0];

        for(int i=1;i<position.size();i++){
            if(position[i] - lastPlaced >= dist){
                count++;
                lastPlaced = position[i];
            }

            if(count >= balls) return true;
        }

        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        int n = position.size();
        sort(position.begin(), position.end());
        int low = 1, high = (position.back() - position[0])/(m-1);
        int result = 1;

        while(low <= high){
            int mid = low + (high - low)/2;
            if(canPlace(position, mid, m)){
                result = mid;
                low = mid + 1;
            }else high = mid - 1;
        }

        return result;
    }
};
