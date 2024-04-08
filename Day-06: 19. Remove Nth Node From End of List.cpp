// 19. Remove Nth Node From End of List (MEDIUM)
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/?envType=daily-question&envId=2024-03-03

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

// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         int count = 0;
//         ListNode* temp = head;
//         while (temp) {
//             temp = temp->next;
//             count++;
//         }

//         if (count == n) {
//             ListNode* delnode=head;
//             head = head->next;
//             delete delnode;
//             return head;
//         }

//         if (count < n) return head;
//         int res=count-n;
//         temp = head;
//         while(temp){
//             res--;
//             if(res==0)
//                 break;
//             temp=temp->next;
//         }

//         ListNode* temp2=temp->next;
//         temp->next=temp->next->next;
//         delete temp2;
//         return head;
//     }
// };


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast=head;
        ListNode* slow=head;

        for(int i=0;i<n;i++)
            fast=fast->next;

        if(!fast) return head->next;

        while(fast && fast->next){
            fast=fast->next;
            slow=slow->next;
        }

        ListNode* delnode=slow->next;
        if(slow->next)
            slow->next=slow->next->next;
        else 
            slow->next=nullptr;
        delete delnode;
        return head;
    }
};
