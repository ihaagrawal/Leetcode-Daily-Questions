// 1171. Remove Zero Sum Consecutive Nodes from Linked List (MEDIUM)
// https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/?envType=daily-question&envId=2024-03-12

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeZeroSumSublists(struct ListNode* head) {
    struct ListNode* dummy=(struct ListNode*)malloc(sizeof(struct ListNode));
    dummy->next=head;
    struct ListNode* current=dummy;
    while(current)
        {
            int sum=0;
            struct ListNode* temp=current->next;
            while(temp)
                {
                    sum+=temp->val;
                    if(sum==0)
                        {
                            current->next=temp->next;
                            break;
                        }
                    temp=temp->next;
                }
            if (!temp) 
                current = current->next;
        }
    
    return dummy->next;
}
