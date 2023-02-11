class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix[0].size();
        
        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-i-1;j++){
//              Anti-Clockwise   
                // int temp = matrix[i][j];
                
//                 matrix[i][j] = matrix[j][n-1-i];
//                 matrix[j][n-1-i] = matrix[n-1-i][n-1-j];
//                 matrix[n-1-i][n-1-j] = matrix[n-1-j][i];
                       
//                 matrix[n-1-j][i] = temp;
                
                // Clockwise
                int temp2 = matrix[i][j];
                
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                       
                matrix[j][n-1-i] = temp2;
            }
        }
        
        return;
    }
};