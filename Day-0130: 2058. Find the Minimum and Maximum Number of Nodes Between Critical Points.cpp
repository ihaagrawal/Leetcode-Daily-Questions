// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points (MEDIUM)
// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/description/?envType=daily-question&envId=2024-07-05


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        ListNode* prev = head;
        ListNode* curr = head->next;
        ListNode* next = curr->next;

        vector<int> criticalPoints;
        int index = 1;

        while (next) {
            if ((curr->val > prev->val && curr->val > next->val) || 
                (curr->val < prev->val && curr->val < next->val)) {
                criticalPoints.push_back(index);
            }

            prev = curr;
            curr = next;
            next = next->next;
            ++index;
        }

        if (criticalPoints.size() < 2) return {-1, -1};

        int minDist = INT_MAX;
        for (int i = 1; i < criticalPoints.size(); ++i) {
            minDist = min(minDist, criticalPoints[i] - criticalPoints[i - 1]);
        }

        int maxDist = criticalPoints.back() - criticalPoints.front();
        return {minDist, maxDist};
    }
};
