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
    ListNode *detectCycle(ListNode *head) {
        ListNode *temp = head,*ptr = head;
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        
        while(temp != NULL && temp->next != NULL){
            ptr = ptr->next;
            temp = temp->next->next;
            
            if(ptr == temp){
                break;
            }
        }
        
        if(temp == NULL || temp->next == NULL)
            return NULL;
        
        while(head != ptr){
            head = head->next;
            ptr = ptr->next;
        }
        
        return head;
    }
};