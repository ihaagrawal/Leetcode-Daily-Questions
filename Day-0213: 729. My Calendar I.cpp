// 729. My Calendar I (MEDIUM)
// https://leetcode.com/problems/my-calendar-i/description/?envType=daily-question&envId=2024-09-26

class MyCalendar {
public:
    unordered_map<int, int> mp;
    MyCalendar() {}
    
    bool book(int x, int y) {
        for(auto& num : mp) {
            int a = num.first, b = num.second;

            if(a < y && b > x) return false;
            if(x < b && y > a) return false;
            if(a <= x && y <= b) return false;
            if(x < a && b < y) return false;

        }
        mp[x] = y;
        return true;
    }
};
