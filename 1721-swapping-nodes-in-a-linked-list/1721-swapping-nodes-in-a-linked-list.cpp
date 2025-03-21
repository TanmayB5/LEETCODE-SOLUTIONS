class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        int cnt = 0;
        ListNode* curr = head;

        // Step 1: Count the number of nodes
        while (curr) {
            cnt++;
            curr = curr->next;
        } 

        int n = cnt - k + 1;

        // Step 2: Find the k-th node from the front
        curr = head; // Reset curr to head
        for (int i = 1; i < k; i++) {
            curr = curr->next;
        }
        ListNode* front = curr; // Store k-th node from front

        // Step 3: Find the k-th node from the back
        curr = head; // Reset curr to head again
        for (int i = 1; i < n; i++) {
            curr = curr->next;
        }
        ListNode* back = curr; // Store k-th node from back

        // Step 4: Swap the values of the two nodes
        swap(front->val, back->val);

        return head;
    }
};
