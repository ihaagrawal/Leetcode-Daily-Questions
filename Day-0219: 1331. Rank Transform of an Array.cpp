// 1331. Rank Transform of an Array (EASY)
// https://leetcode.com/problems/rank-transform-of-an-array/description/?envType=daily-question&envId=2024-10-02


class Solution {
public:

    static bool comp(pair<int, int>& a, pair<int, int>& b){
        return a.second < b.second;
    }

    vector<int> arrayRankTransform(vector<int>& vec) {
        int n = vec.size();
        if(n < 1) return vec;
        if(n == 1) return {1};

        vector<pair<int, int>> arr(n);
        for(int i=0;i<n;i++){
            arr[i].first = vec[i];
            arr[i].second = i;
        }
        sort(arr.begin(), arr.end());
        int last = arr[0].first;
        arr[0].first = 1;
        int rank = 1;

        for(int i=1;i<n;i++){
            if(arr[i].first != last){
                last = arr[i].first;
                rank++;
            }
            arr[i].first = rank;
        }

        sort(arr.begin(), arr.end(), comp);
        for(int i=0;i<n;i++) vec[i] = arr[i].first;
        return vec;
    }
};
