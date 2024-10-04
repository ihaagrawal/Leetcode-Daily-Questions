// 2491. Divide Players Into Teams of Equal Skill (MEDIUM)
// https://leetcode.com/problems/divide-players-into-teams-of-equal-skill/description/?envType=daily-question&envId=2024-10-04


class Solution {
public:
    long long dividePlayers(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        long long sum = arr[0] + arr[n-1];
        long long total = arr[0] * arr[n-1];
        int i = 1, j = n-2;
        while(i < j){
            long long s = arr[i] + arr[j];
            if(s != sum) return -1;
            total += (arr[i] * arr[j]);
            i++;
            j--;
        }

        return total;
    }
};
