// 141. Linked List Cycle (EASY)
// https://leetcode.com/problems/linked-list-cycle/description/?envType=daily-question&envId=2024-03-06

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head) return false;
        ListNode* temp=head;
        while(temp->next){
            temp->val=INT_MAX;
            temp=temp->next;
            if(temp->val==INT_MAX)
                return true;
        }
        return false;
    }
};
