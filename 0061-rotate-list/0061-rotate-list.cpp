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
        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }
        int c = 0;
        ListNode *t = head;
        while(t){
            c++;
            t = t->next;
        }
        k = k % c;
        
        if(k == 0){
            return head;
        }
        
        // k = c - k;
        
        while(k != 0){
            ListNode *temp = head;
            while(temp->next->next != NULL){
                temp = temp->next;
                // cout << temp->val << " ";
            }
            
            ListNode *ptr = temp;
            ptr = ptr->next;
            // cout << ptr->val << " ";
            temp->next = NULL;
            
            ptr->next = head;
            head = ptr;
            
            
            k--;
        }
        
        return head;
    }
};