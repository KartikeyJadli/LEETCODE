class Solution {
public:
    bool dfs(vector<vector<int>>& grid, int i, int j, int m, int n){
        if(i<0|| j<0 || i>=m || j>=n ) return false;
        if(grid[i][j]) return true;
        if(i==0 || j==0 || i==m-1 || j==n-1) return false;
        grid[i][j] = 1;
        bool a = dfs(grid,i+1,j,m,n);
        bool b = dfs(grid,i,j+1,m,n);
        bool c = dfs(grid,i-1,j,m,n);
        bool d = dfs(grid,i,j-1,m,n);
        return a&&b&&c&&d;
    }
    
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        if(!m) return 0;
        int n = grid[0].size();
        int ans = 0;
        for(int i=1; i<m-1; i++){
            for(int j=1; j<n-1;j++){
                if(grid[i][j] == 0){
                    if(dfs(grid,i,j,m,n)) ans++;
                    //cout<<i<<" "<<j<<" "<<ans<<endl;
                }
            }
        }
        return ans;
    }
};