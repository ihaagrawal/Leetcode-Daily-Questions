// 2181. Merge Nodes in Between Zeros (MEDIUM)
// https://leetcode.com/problems/merge-nodes-in-between-zeros/description/?envType=daily-question&envId=2024-07-04


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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        ListNode* temp = head->next;
        ListNode* temp2 = head->next;

        while(temp){
            if(temp->val == 0){
                int sum = 0;
                while(temp2 != temp){
                    sum += temp2->val;
                    temp2 = temp2->next;
                }
                ListNode* toadd = new ListNode(sum);
                current->next = toadd;
                current = current->next;
                temp2 = temp->next;
                temp = temp->next;
            }else temp = temp -> next;
        }

        return dummy->next;
    }
};
