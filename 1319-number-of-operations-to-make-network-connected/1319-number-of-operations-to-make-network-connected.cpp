class Solution {
public:
    int parent[100000]; 

    int find(int node) {
        if(node == parent[node]){
            return node;
        }

        return parent[node] = find(parent[node]); 
    }

    void parent_union(int a, int b) {
        int u = find(a); 
        int v = find(b); 
        if(u == v){ 
            return;
        }

        parent[u] = v; 
    }

    int makeConnected(int n, vector<vector<int>>& c) {
        if(c.size() < n -1){
            return -1;
        }

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
        
        for(auto it : c){
            parent_union(it[0], it[1]);
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(parent[i] == i) ans++;
        }

        return ans - 1;
    }
};