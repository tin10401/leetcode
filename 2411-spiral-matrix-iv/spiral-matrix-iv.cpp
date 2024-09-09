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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> res(m, vector<int>(n, -1));
        int left = 0;
        int top = 0;
        int right = n - 1;
        int bottom = m -  1;
        while(head)
        {
            for(int i = left; i <= right && head; head = head->next, i++)
            {
                res[top][i] = head->val;
            }
            top++;
            for(int i = top; i <= bottom && head; head = head->next, i++)
            {
                res[i][right] = head->val;
            }
            right--;
            for(int i = right; i >= left && head; head = head->next, i--)
            {
                res[bottom][i] = head->val;
            }
            bottom--;
            for(int i = bottom; i >= top && head; head = head->next, i--)
            {
                res[i][left] = head->val;
            }
            left++;
        }
        return res;
    }
};