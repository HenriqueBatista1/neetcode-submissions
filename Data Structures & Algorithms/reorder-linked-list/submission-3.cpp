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
        ListNode* aux;

        while(curr != nullptr) {
            aux = curr->next;
            curr->next = prev;
            prev = curr;
            curr = aux;
        }

        return prev;
    }

    void merge(ListNode* l1, ListNode* l2) {

        ListNode* next1;
        ListNode* next2;

        while(l1 != nullptr && l2 != nullptr) {

            //Keep the original lists next nodes
            next1 = l1->next;
            next2 = l2->next;

            // Does the swapping/zipper
            l1->next = l2;
            l2->next = next1;

            l1 = next1;
            l2 = next2;
        }
    }

    void reorderList(ListNode* head) {

        if(head == nullptr || head->next == nullptr) return;

        ListNode* slow = head;
        ListNode* fast = head->next;
        ListNode* prev;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second_half = slow->next;

        slow->next = nullptr;

        ListNode* second_half_head = reverse(second_half);

        merge(head, second_half_head);

    }
};
