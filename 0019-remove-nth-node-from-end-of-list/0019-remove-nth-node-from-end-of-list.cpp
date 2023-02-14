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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL){
            return NULL;
        }

        int count = 0;
        ListNode *temp = head,*ptr = head;
        while(temp != NULL){
            count++;
            temp = temp->next;
        }

        if(count == n){
            return head->next;
        }
        
        int temp2 = count - n - 1;
        while(temp2--){
            ptr = ptr->next;
        }

        ptr->next = ptr->next->next;
        return head;
    }
};