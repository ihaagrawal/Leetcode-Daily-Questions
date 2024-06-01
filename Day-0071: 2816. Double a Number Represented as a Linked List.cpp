// 2816. Double a Number Represented as a Linked List (MEDIUM)
// https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/description/?envType=daily-question&envId=2024-05-07

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

    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode* newHead=reverseList(head->next);
        ListNode* front=head->next;
        front->next=head;
        head->next=nullptr;
        return newHead;
    }

    ListNode* doubleIt(ListNode* head) {        
        ListNode* temp = reverseList(head);
        ListNode* dummy = new ListNode(0);
        ListNode* current = dummy; 
        int carry=0;
        while(temp){
            int data = 2*temp->val+carry;
            carry=0;
            if(data>9){
                carry=1;
                data=data-10;
            }
            current->next = new ListNode(data); 
            current = current->next; 
            temp=temp->next;
        }
        if (carry > 0) {
            current->next = new ListNode(carry); 
        }
        ListNode* result = reverseList(dummy->next); 
        delete dummy; 
        return result;
    }

};
