class Solution {
public:
    int count;
    void dfs(int i, vector<int> adj[], vector<int> &vis){
        vis[i] = true;
        count++;
        for(auto itr:adj[i]){
            if(vis[itr] == false)
                dfs(itr,adj,vis);
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto itr:edges){
            adj[itr[0]].push_back(itr[1]);
            adj[itr[1]].push_back(itr[0]);
        }

        vector<int> vis(n,false);
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                count = 0;
                dfs(i,adj,vis);
                ans.push_back(count);
            }
        }

        long long temp = 0;
        int m = ans.size();
        vector<long long>pref(m);
        pref[m-1] = ans[m-1];

        for(int i=m-2;i>=0;i--){
            pref[i] = ans[i] + pref[i+1];
        }

        for(int i=0;i<m-1;i++){
            temp = temp + (long long)ans[i]*(long long)pref[i+1];
        }

        return temp;
        
    }
};