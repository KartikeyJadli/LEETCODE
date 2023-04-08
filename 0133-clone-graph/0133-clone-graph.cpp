/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        
        unordered_map<Node*, Node*> mp;
        queue<Node*> q;
        Node* temp = new Node(node->val, vector<Node*>());
        q.push(node);
        mp[node] = temp;
        
        while(!q.empty()) {
            Node* curr = q.front();
            q.pop();
            
            for(auto next: curr->neighbors) {
                if (mp.find(next) == mp.end()) {
                    Node* ptr = new Node(next->val, vector<Node*>());
                    mp[next] = ptr;
                    q.push(next);
                }

                (mp[curr]->neighbors).push_back(mp[next]);
            }
        }

        return temp;
    }
};