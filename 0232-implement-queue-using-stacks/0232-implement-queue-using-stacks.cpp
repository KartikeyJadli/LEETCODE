class MyQueue {
public:
    struct node{
        int data;
        struct node *next;
    }; typedef struct node node;
    MyQueue() {
    }
    node *head = NULL,*myque = NULL;
    void push(int x) {
        if(myque == NULL){
            head = new node();
            head->data = x;
            head->next = NULL;
            myque = head;
        }

        else{
            node *ptr;
            ptr = new node();
            ptr->data = x;
            ptr->next = NULL;
            myque->next = ptr;
            myque = myque->next;
        }
    }
    
    int pop() {
        node *ptr = head;
        head = head->next;
        int val = ptr->data;
        delete(ptr);
        myque = head == NULL ? NULL : myque;
        return val;
    }
    
    int peek() {
        return head->data;
    }
    
    bool empty() {
        return head == NULL;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */