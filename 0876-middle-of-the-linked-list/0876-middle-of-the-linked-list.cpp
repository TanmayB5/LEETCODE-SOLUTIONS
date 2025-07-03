class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode *temp = head;
        int count = 0;
        
        // First pass to count the number of nodes
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }

        // Find middle node position (0-indexed)
        int node = count / 2;

        // Second pass to reach the middle node
        while (node > 0) {
            head = head->next;
            node--;
        }

        return head;
    }
};
