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
    // solution by tinle
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast)
        {
            if(n-- <= -1)
            {
                slow = slow->next;
            }
            fast = fast->next;
        }
        if(n > -1)
        {
            return head->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};