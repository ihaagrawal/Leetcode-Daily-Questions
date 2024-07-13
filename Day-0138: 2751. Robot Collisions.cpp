// 2751. Robot Collisions (HARD)
// https://leetcode.com/problems/robot-collisions/description/?envType=daily-question&envId=2024-07-13


class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        
        vector<pair<int, int>> robot(n);
        for(int i = 0; i < n; i++) {
            robot[i] = {positions[i], i};
        }
        
        sort(robot.begin(), robot.end(), greater<pair<int, int>>());

        vector<int> vec;
        for(auto& [pos, i] : robot) {
            if(directions[i] == 'L') {
                vec.push_back(i);
            } else {
                while(!vec.empty() && healths[i] > 0) {
                    int back = vec.back();
                    int diff = healths[back] - healths[i];
                    if(diff > 0) {
                        healths[back]--;
                        healths[i] = 0;
                    } else if(diff < 0) {
                        healths[back] = 0;
                        healths[i]--;
                        vec.pop_back();
                    } else {
                        healths[i] = healths[back] = 0;
                        vec.pop_back();
                    }
                }
            }
        }

        vector<int> result;
        for(int it : healths) {
            if(it > 0) result.push_back(it);
        }

        return result;
    }
};
