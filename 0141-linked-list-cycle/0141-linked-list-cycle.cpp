/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
     ListNode *slow = head;
     ListNode *fast = head->next;
     while(slow!=nullptr && fast!=nullptr){
        if(slow->val == fast->val){
            return true;
        } else {
            slow = slow->next;
            fast = fast->next->next;
        }
     }   
     return false;
    }
};