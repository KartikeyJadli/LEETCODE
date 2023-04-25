class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        int sum = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    if((j-1) < 0 || grid[i][j-1] == 0){ 
                        sum++;
                    }
                    
                    if((j+1) == c || grid[i][j+1] == 0){ 
                        sum++;
                    }
                    
                    if((i-1) < 0 || grid[i-1][j] == 0){
                        sum++;
                    }
                    
                    if((i+1) == r || grid[i+1][j] == 0){ 
                        sum++;
                    }
                }
            }
        }

        return sum;
    }
};