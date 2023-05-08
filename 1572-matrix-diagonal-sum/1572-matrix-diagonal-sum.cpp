class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0,x = 0, y = mat[0].size() - 1;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<mat[0].size();j++){
                if(j == x || j == y){
                    sum = sum + mat[i][j];
                }
            }
            x = x + 1;
            y = y - 1;
        }
        
        return sum;
    }
};