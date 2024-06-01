// 1700. Number of Students Unable to Eat Lunch (EASY)
// https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/?envType=daily-question&envId=2024-04-08

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int stu=students.size(), sand=sandwiches.size();
        int count=0;
        while(count<stu){
            if(students[0]==sandwiches[0]){
                students.erase(students.begin());
                sandwiches.erase(sandwiches.begin());
                stu--;
                sand--;
                count=0;
            }
            else{
                int n=students[0];
                students.erase(students.begin());
                students.push_back(n);
                count++;
            }
            
        }
        return count;
    }
};
