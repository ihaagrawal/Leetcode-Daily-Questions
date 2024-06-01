// 621. Task Scheduler (MEDIUM)
// https://leetcode.com/problems/task-scheduler/description/?envType=daily-question&envId=2024-03-19

class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] char_count=new int[26];
        for(char c: tasks){
            char_count[c-'A']++;
        }

        Arrays.sort(char_count);
        int max_value=char_count[25]-1;
        int idle_slots=max_value * n;

        for(int i=24;i>=0;i--){
            idle_slots -= Math.min(char_count[i], max_value);
        }

        return idle_slots > 0 ? idle_slots + tasks.length : tasks.length;
    }
}
