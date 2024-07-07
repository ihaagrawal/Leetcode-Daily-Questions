// 2582. Pass the Pillow (EASY)
// https://leetcode.com/problems/pass-the-pillow/description/?envType=daily-question&envId=2024-07-06

class Solution {
public:
    int passThePillow(int n, int time) {
        int quo = time / (n-1), rem = time % (n-1);
        return (quo % 2 == 0) ? rem + 1 : n - rem;
    }
};
