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
    ListNode* reverse(ListNode* l){
        ListNode * curr = l;
        ListNode *next = nullptr;
        ListNode* prev = nullptr;

        while(curr){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       l1 = reverse(l1);
       l2 = reverse(l2);
        ListNode *dummy = new ListNode();
        ListNode *node = dummy;
        int c = 0;
        while(l1 || l2){
            int x = (l1 ? l1->val: 0);
            int y = (l2 ? l2->val: 0);
            int sum = x + y + c;

            c = sum/10;
            node->next = new ListNode(sum%10);
            node = node->next;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;

        }
        if(c>0){
            node->next = new ListNode(c);
        }
        ListNode* ans = reverse(dummy->next);
        return ans;
    }
};