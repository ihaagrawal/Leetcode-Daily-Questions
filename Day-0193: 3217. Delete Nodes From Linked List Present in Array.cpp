// 3217. Delete Nodes From Linked List Present in Array (MEDIUM)
// https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/description/?envType=daily-question&envId=2024-09-06


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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int n = nums.size();
        map<int, int> mp;
        for(int i=0;i<n;i++) mp[nums[i]]++;

        ListNode* dummy = new ListNode(-1);
        ListNode* current = dummy;

        ListNode* temp = head;
        while(temp){
            if(mp.find(temp->val) == mp.end()){
                ListNode* newnode = new ListNode(temp->val);
                current->next = newnode;
                current = current->next;
            }
            temp = temp->next;
        }

        return dummy->next;
    }
};
