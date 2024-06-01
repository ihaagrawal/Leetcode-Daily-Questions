// 206. Reverse Linked List (EASY)
// https://leetcode.com/problems/reverse-linked-list/description/?envType=daily-question&envId=2024-03-21

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
        
        ListNode* reversed=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;

        return reversed;
    }
};
