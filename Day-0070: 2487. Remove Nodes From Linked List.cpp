// 2487. Remove Nodes From Linked List (MEDIUM)
// https://leetcode.com/problems/remove-nodes-from-linked-list/description/?envType=daily-question&envId=2024-05-06

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextTemp;
        }
        return prev;
    }

    ListNode* removeNodes(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        stack<int> st;
        while (head) {
            while (!st.empty() && st.top() < head->val) st.pop();
            st.push(head->val);
            head = head->next;
        }

        while (!st.empty()) {
            ListNode* newNode = new ListNode(st.top());
            st.pop();
            prev->next = newNode;
            prev = prev->next;
        }

        ListNode* newHead = reverseList(dummy.next);
        return newHead;
    }
};
