// 143. Reorder List (MEDIUM)
// https://leetcode.com/problems/reorder-list/description/?envType=daily-question&envId=2024-03-23

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
    void reorderList(ListNode* head) {
    if (!head || !head->next) return;

    // Find the middle of the list
    ListNode *slow = head, *fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Split the list into two halves
    ListNode *second = slow->next;
    slow->next = nullptr;

    // Reverse the second half
    ListNode *prev = nullptr, *curr = second, *next = nullptr;
    while (curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    second = prev;

    // Merge the two halves
    ListNode *first = head;
    while (second) {
        ListNode *temp1 = first->next, *temp2 = second->next;
        first->next = second;
        second->next = temp1;
        first = temp1;
        second = temp2;
    }
}

};
