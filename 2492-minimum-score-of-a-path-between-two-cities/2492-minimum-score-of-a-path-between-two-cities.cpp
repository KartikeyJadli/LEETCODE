class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int ans = INT_MAX; 
        vector<vector<pair<int, int>>> v(n + 1); 
        for(auto r: roads){
            v[r[0]].push_back({r[1],r[2]});
            v[r[1]].push_back({r[0],r[2]});
        }

        vector<int> visited(n+1, 0);
        queue<int> q;
        q.push(1); 
        visited[1] = 1;
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto i: v[node]){
                ans = min(ans,i.second);
                if(visited[i.first] != 1){
                    visited[i.first] = 1;
                    q.push(i.first);
                }
            }
        }

        return ans;
    }
};