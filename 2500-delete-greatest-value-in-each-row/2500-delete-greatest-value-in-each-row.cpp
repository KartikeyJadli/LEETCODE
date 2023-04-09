class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int n = grid.size(),m = grid[0].size();
        if(n == 1 && m == 1){
            return grid[n-1][m-1];
        }

        for(int i=0; i<n; i++){
            sort(grid[i].rbegin(), grid[i].rend());
        }
        
        int count = 0;
        for(int i=0; i<m; i++){
            int val = grid[0][i];
            for(int j=1; j<n; j++){
                val = max(val, grid[j][i]);
            }

            count += val;
        }

        return count;
    }
};