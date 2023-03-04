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
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }

        priority_queue<int,vector<int>,greater<int>> pq;
        ListNode *temp = head;
        while(temp != NULL){
            pq.push(temp->val);
            temp = temp->next;
        }

        ListNode *ptr = new ListNode(pq.top());
        pq.pop();
        ListNode *ptr2 = ptr;

        while(!pq.empty()){
            ListNode *temp2 = new ListNode(pq.top());
            pq.pop();
            ptr2->next = temp2;
            ptr2 = ptr2->next;
        }

        head = ptr;
        return head;
    }
};