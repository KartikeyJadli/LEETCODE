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
    ListNode *head;
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        ListNode *temp = head,*ptr;
        int n = 1;
        while(temp != NULL){
            if(rand() % n == 0){
                ptr = temp;
            }

            temp = temp->next;
            n++;
        }

        return ptr->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */