// 2418. Sort the People (EASY)
// https://leetcode.com/problems/sort-the-people/description/?envType=daily-question&envId=2024-07-22


class Solution {
public:

    static bool comp(pair<int, string>& a, pair<int, string>& b) {
        return a.first > b.first;
    }

    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();

        vector<pair<int, string>> students;
        for(int i = 0; i < n; i++) {
            students.emplace_back(heights[i], names[i]);
        }

        sort(students.begin(), students.end(), comp);

        vector<string> sorted;
        for(int i = 0; i < n; i++) {
            sorted.push_back(students[i].second);
        }

        return sorted;
    }
};
