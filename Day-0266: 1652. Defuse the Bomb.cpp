// 1652. Defuse the Bomb (EASY)
// https://leetcode.com/problems/defuse-the-bomb/description/?envType=daily-question&envId=2024-11-18


class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);

        if(k == 0) return result;

        if(k > 0){
            for(int i=0;i<n;i++){
                int j = k, index = i+1;
                while(j--){
                    if(index == n) index = 0;
                    result[i] += code[index];
                    index++;
                }
            }
        }

        if(k < 0){
            k = -k;
            for(int i=0;i<n;i++){
                int j = k, index = i-1;
                while(j--){
                    if(index == -1) index = n-1;
                    result[i] += code[index];
                    index--;
                }
            }
        }

        return result;
    }
};
