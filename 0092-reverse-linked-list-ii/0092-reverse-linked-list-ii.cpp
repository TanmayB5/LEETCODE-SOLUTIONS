class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* beforeleft = nullptr;  // Node before `left`
        ListNode* leftnode = nullptr;    // First node of the reversed section
        int index = 1;

        // Traverse to `left` position
        while (curr && index < left) {
            beforeleft = curr;
            curr = curr->next;
            index++;
        }

        // Start reversing from `left` to `right`
        leftnode = curr; // Store `left` node to reconnect later
        while (curr && index <= right) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
            index++;
        }

        // Connect the reversed part to the rest of the list
        if (beforeleft) {
            beforeleft->next = prev;  // Connect node before `left` to the new head of reversed part
        } else {
            head = prev;  // If `left` was 1, update `head`
        }

        if (leftnode) {
            leftnode->next = curr; // Connect `leftnode` to the node after `right`
        }

        return head;
    }
};
