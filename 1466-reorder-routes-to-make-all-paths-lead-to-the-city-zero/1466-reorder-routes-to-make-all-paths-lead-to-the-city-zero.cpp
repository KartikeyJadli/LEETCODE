class Solution {
public:
    int ans = 0;
    vector<pair<int,int>> adj[50005];
    int visited[50005];
    
    void dfs(int c){
        visited[c] = 1;
        
        for(auto p:adj[c]){
            if(!visited[p.first]){
                ans += p.second;
                dfs(p.first);
            }
        }
        
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        for(int i=0;i<connections.size();i++){
            auto p = make_pair(connections[i][1],1);
            adj[connections[i][0]].push_back(p);
            p = make_pair(connections[i][0],0);
            adj[connections[i][1]].push_back(p);
        }
        dfs(0);
        
        return ans;
    }
};