// 234. Palindrome Linked List (EASY)
// https://leetcode.com/problems/palindrome-linked-list/description/?envType=daily-question&envId=2024-03-22

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

    ListNode* reverseList(ListNode* newList) {
        if(!newList || !newList->next) return newList;
        ListNode* current=newList;
        ListNode* prev=NULL;
        ListNode* next;
        while(current){
            next=current->next;
            current->next=prev;
            prev=current;
            current=next;
        }
        newList=prev;
        return newList;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* fast=head;
        ListNode* slow=head;

        while(fast && fast->next){
            fast=fast->next->next;
            slow=slow->next;
        }

        ListNode* reversed=reverseList(slow);

        ListNode* temp=head;
        while(temp!=slow && reversed!=nullptr){
            if(temp->val!=reversed->val)
                return false;
            temp=temp->next;
            reversed=reversed->next;
        }
        return true;
    }
};
