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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode dummy;
        dummy.next = head;
        head = &dummy;

        ListNode* left = head, *right = head->next;

        for(int i = 0; i < n; i++) {
            right = right->next;
        }

        while(right != nullptr) {
            right = right->next;
            left = left->next;
        }

        left->next = left->next->next;

        return head->next;
    }
};
