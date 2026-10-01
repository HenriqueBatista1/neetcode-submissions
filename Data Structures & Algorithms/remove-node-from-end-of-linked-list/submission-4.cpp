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

    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while(curr != nullptr) {
            ListNode* aux = curr->next;
            curr->next = prev;
            prev = curr;
            curr = aux;
        }

        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head == nullptr || head->next == nullptr) return nullptr;

        ListNode* new_head = reverse(head);
        ListNode* prev = nullptr;
        ListNode* curr = new_head;

        int i = 1;

        while(curr != nullptr) {
            
            if(n == 1) {
                new_head = curr->next;
                curr->next == nullptr;
                break;
            }

            if(i == n) {
                prev->next = curr->next;
                curr->next = nullptr;
                break;
            }

            prev = curr;
            curr = curr->next;

            i++;
        }

        ListNode* final_list_head = reverse(new_head);

        return final_list_head;
    }
};
