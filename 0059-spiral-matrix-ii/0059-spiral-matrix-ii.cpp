class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n == 1){
            return {{1}};
        }

        vector<vector<int>> v(n,vector<int>(n));
        int num = 1;

        for(int i=0;i<(n + 1)/2;i++){
            // left to right
            for(int j=i;j<n - i;j++){
                v[i][j] = num++;
            }

            // top to bottom
            for(int j=i+1;j<n - i;j++){
                v[j][n - i - 1] = num++;                
            }

            // right to left
            for(int j=n - i - 2;j>=i;j--){
                v[n - i - 1][j] = num++;
            }

            // bottom to top
            for(int j=n - i - 2;j>i;j--){
                v[j][i] = num++;
            }
        }

        return v;
    }
};