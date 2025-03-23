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
    ListNode* doubleIt(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        int carry = 0;

        // Step 1: Reverse the linked list in-place
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        
        head = prev;  // Head now points to the reversed list
        curr = head;
        prev = nullptr;

        // Step 2: Multiply by 2 and handle carry
        while (curr) {
            int newVal = (curr->val * 2) + carry;
            curr->val = newVal % 10;
            carry = newVal / 10;

            prev = curr;  // Store the last processed node
            curr = curr->next;
        }

        // If there's a carry left after the last digit, add a new node
        if (carry > 0) {
            prev->next = new ListNode(carry);
        }

        // Step 3: Reverse back to restore order
        prev = nullptr;
        curr = head;
        while (curr) {
            ListNode* nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        return prev;  // New head after reversing back
    }
};
