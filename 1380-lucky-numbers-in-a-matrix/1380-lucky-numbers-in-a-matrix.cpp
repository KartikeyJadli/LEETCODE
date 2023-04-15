class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n = matrix.size(),m = matrix[0].size();
        vector<int> v;
        for(int i=0;i<n;i++) {
            int minn = 1e9;
            for(int j=0;j<m;j++){
                minn = min(matrix[i][j], minn);
            }

            for(int j=0;j<m;j++) {
                if(minn == matrix[i][j]) {
                    bool isMax = true;
                    for(int k=0;k<n;k++) {
                        if(matrix[i][j] < matrix[k][j]) {
                            isMax = false;
                            break;
                        }
                    }

                    if(isMax){
                        v.push_back(minn);
                    }
                }
            }
        }

        return v;
    }
};