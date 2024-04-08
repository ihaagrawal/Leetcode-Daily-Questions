// 1669. Merge In Between Linked Lists (MEDIUM)
// https://leetcode.com/problems/merge-in-between-linked-lists/?envType=daily-question&envId=2024-03-20

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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* l1 = list1;
        ListNode* l12 = list1;
        ListNode* l2 = list2;
        int n=1;
        while(n<a && l1->next!=NULL)
            {
                l1=l1->next;
                n++;
            }
        n=1;
        while(n<=b && l12->next!=NULL)
            {
                l12=l12->next;
                n++;
            }

        l1->next=l2;
        while(l2->next!=NULL)
            l2=l2->next;
        l2->next=l12->next;

        return list1;
        
    }
};
