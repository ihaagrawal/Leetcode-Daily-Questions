// 2807. Insert Greatest Common Divisors in Linked List (MEDIUM)
// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/description/?envType=daily-question&envId=2024-09-10

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

struct ListNode* insertGreatestCommonDivisors(struct ListNode* head){
    if(!head) return NULL;
    struct ListNode* temp=head;
    if(temp->next==NULL) return head;
    struct ListNode* temp1=head->next;
    while(temp1!=NULL)
        {
            int gcd_val=gcd(temp->val, temp1->val);
            struct ListNode* newnode=(struct ListNode*)malloc(sizeof(struct ListNode));
            newnode->val=gcd_val;
            temp->next=newnode;
            newnode->next=temp1;
            temp=temp1;
            temp1=temp->next;
        }
    return head;
}
