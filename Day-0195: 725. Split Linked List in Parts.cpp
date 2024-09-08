// 725. Split Linked List in Parts (MEDIUM)
// https://leetcode.com/problems/split-linked-list-in-parts/description/?envType=daily-question&envId=2024-09-08

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;
        while (temp) {
            temp = temp->next;
            n++;
        }

        int partSize = n / k; 
        int extra = n % k;    
        
        vector<ListNode*> result(k, nullptr); 
        ListNode* current = head;
        
        for (int i = 0; i < k && current != nullptr; ++i) {
            result[i] = current; 
            int currentPartSize = partSize + (extra > 0 ? 1 : 0); 
            extra--;
            
            for (int j = 1; j < currentPartSize; ++j) {
                if (current) current = current->next;
            }
            
            if (current) {
                ListNode* next = current->next;
                current->next = nullptr; 
                current = next; 
            }
        }
        
        return result;
    }
};
