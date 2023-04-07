class Solution {
public:
        int numEnclaves(vector<vector<int>>& A) {
        int N = A.size();
        int M = A[0].size();
        
        for(int i = 0; i < N; ++i){
            if(A[i][0]) walk(A, i, 0);
            if(A[i][M-1]) walk(A, i, M-1);
        }
        
        for(int j = 0; j < M; ++j){
            if(A[0][j]) walk(A, 0, j);
            if(A[N-1][j]) walk(A, N-1, j);
        }
        
        int ans = 0;
        for(int i = 1; i < N; ++i){
            for(int j = 1; j < M; ++j){
                if(A[i][j]) ++ans;
            }
        }
        return ans;
    }
    
    void walk(vector<vector<int>>& A, int i, int j){
        if(i < 0 || i >= A.size() || j < 0 || j >= A[0].size()) return;
        
        if(A[i][j]) A[i][j] = 0;
        else return;

        walk(A, i   , j+1);
        walk(A, i+1 , j);
        walk(A, i   , j-1);
        walk(A, i-1 , j);
        
    }
};