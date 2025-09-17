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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr || head->next == nullptr){return head;}

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode * prev = dummy;

        for(int i=1;i<left;i++){
            prev = prev->next;
        }

        //reverse the list
        ListNode* curr = prev->next;
        ListNode* nxt = nullptr;
        ListNode* prevNode = nullptr;

        for (int i = 0; i < right - left + 1; i++) {
            nxt = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr = nxt;
        }

        prev->next->next = curr;
        prev->next = prevNode;
       return dummy->next;
    }
};