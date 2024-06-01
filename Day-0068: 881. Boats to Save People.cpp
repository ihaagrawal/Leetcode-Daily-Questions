// 881. Boats to Save People (MEDIUM)
// https://leetcode.com/problems/boats-to-save-people/description/?envType=daily-question&envId=2024-05-04

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int left = 0, right = n - 1;
        int count = 0;
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                count++;
                left++;
                right--;
            } else {
                count++;
                right--;
            }
        }
        return count;
    }
};
