class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Step 1: Count the length
        int length = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            length++;
            temp = temp->next;
        }

        // Step 2: If we need to remove the first node
        if (n == length) {
            return head->next;
        }

        // Step 3: Find the (length - n)th node
        temp = head;
        for (int i = 1; i < length - n; i++) {
            temp = temp->next;
        }

        // Step 4: Remove the target node
        temp->next = temp->next->next;

        return head;
    }
};
