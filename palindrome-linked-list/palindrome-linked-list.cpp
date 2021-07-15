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
    ListNode* reverse(ListNode* head){
        ListNode* newhead=NULL;
        while(head!=NULL){
            ListNode* Nextnode = head->next;
            head->next = newhead;
            newhead=head;
            head=Nextnode;
        }
        return newhead;
    }
    bool isPalindrome(ListNode* head) {
        //Find the middle of the linked list 
        ListNode* slow=head;
        ListNode* fast=head;
        //As we have to stop at the last node or second last node
        while(fast->next!=NULL and fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        slow->next = reverse(slow->next);
        //move the slow pointer one step forward as the middle is not to be compared
        slow = slow->next;
        while(slow!=NULL){
            if(slow->val != head->val)
                return false;
            slow= slow->next;
            head= head->next;
        }
        return true;
    }
};