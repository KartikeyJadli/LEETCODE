class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> res(n, vector<int>(n, -1));
        queue<int> q;
        for(int i = 0;i < n; i++){
            for(int j = 0; j < n;j++){
                if(grid[i][j] == 1){
                    res[i][j] = 0;
                    q.push(i * n + j);
                }
            }
        }
        
        vector<int> dx{ 0, 1, 0, -1 };
        vector<int> dy{ 1, 0, -1, 0 };
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            int i = cur / n;
            int j = cur % n;
            
            for(int k = 0; k < 4; k++){
                int x = i + dx[k];
                int y = j + dy[k];
                
                if(x >= 0 && y >= 0 && x < n && y < n){
                    if(res[x][y] == -1){
                        res[x][y] = res[i][j] + 1;
                        q.push(x * n + y);
                    }
                }
            }
        }
        
        int maxnum = -1;
        
        for(int i = 0;i < n; i++){
            for(int j = 0;j < n;j++){
                maxnum = max(maxnum, res[i][j]);
            }
        }
        
        if(maxnum == 0){ 
            return -1;
        }
        
        return maxnum;
    }
};