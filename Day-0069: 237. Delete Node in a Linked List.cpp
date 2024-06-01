// 237. Delete Node in a Linked List (MEDIUM)
// https://leetcode.com/problems/delete-node-in-a-linked-list/description/


class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* temp=node;
        while(temp->next){
            temp->val=temp->next->val;
            if(!temp->next->next){
                delete temp->next;
                temp->next=nullptr;
                return;
            }
            temp=temp->next;
        }
    }
};
