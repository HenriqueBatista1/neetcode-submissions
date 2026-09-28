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

    ListNode* merge(ListNode* l1, ListNode* l2) {
        
        ListNode* head = l1;
        ListNode* next1;
        ListNode* next2;
        ListNode* prev;

        while(l1 != nullptr && l2 != nullptr) {
            next1 = l1->next;
            next2 = l2->next;
            
            if(next1 == nullptr) prev = l2;
            if(next2 == nullptr) prev = l1;

            l1->next = l2;
            l2->next = next1;
            l1 = next1;
            l2 = next2;
        }

        if(l1 != nullptr) prev->next = l1;
        if(l2 != nullptr) prev->next = l2; 


        return head;

    }

    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev;

        while(fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        if(prev != nullptr) prev->next = nullptr;

        ListNode* second_half_head = reverse(slow);

        ListNode* reordered_list = merge(head, second_half_head);

    }
};
