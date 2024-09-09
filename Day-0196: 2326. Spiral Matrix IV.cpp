// 2326. Spiral Matrix IV (MEDIUM)
// https://leetcode.com/problems/spiral-matrix-iv/description/

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
    vector<vector<int>> spiralMatrix(int n, int m, ListNode* head) {
        vector<vector<int>> matrix(n, vector<int>(m, -1));
        int top = 0, bottom = n-1, left = 0, right = m-1;
        ListNode* temp = head;

        while(temp && top <= bottom && left <= right){
            for(int j=left;j<=right;j++){
                if(temp){
                    matrix[top][j] = temp->val;
                    temp = temp->next;
                }
            }top++;

            for(int j=top;j<=bottom;j++){
                if(temp){
                    matrix[j][right] = temp->val;
                    temp = temp->next;
                }
            }right--;

            if(right >= left){
                for(int j=right;j>=left;j--){
                    if(temp){
                        matrix[bottom][j] = temp->val;
                        temp = temp->next;
                    }
                }bottom--;
            }

            if(bottom >= top){
                for(int j=bottom;j>=top;j--){
                    if(temp){
                        matrix[j][left] = temp->val;
                        temp = temp->next;
                    }
                }left++;
            }
        }

        return matrix;
    }
};
