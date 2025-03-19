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
     ListNode* deleteMiddle(ListNode* head) {
        // Edge case: If there is only one node, return nullptr
        if (head == nullptr || head->next == nullptr) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;  // To track the node before `slow`

        // Move slow (1 step) and fast (2 steps)
        while (fast != nullptr && fast->next != nullptr) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // Delete middle node by skipping it
        prev->next = slow->next;
        delete slow;  // Free the memory of the deleted node

        return head;
    }
};