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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next == NULL || k==0)return head;
        //Finding the length of the linked list
        ListNode* curr = head;
        int len=1;
        while(curr->next){
              len++;
            curr=curr->next;
        }
        //point the last node to front of the original linked list
        curr->next=head;
        k = k%len; 
        // k can be huge it has to be brought down to less than the length of the linked list
        k = len - k;
        while(k--){
            //As current is pointed to head it starts traversal from head
            curr=curr->next;
        }
        head = curr->next;
        curr->next = NULL;
        
        return head;
        
    }
};