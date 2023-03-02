class Solution {
public:
    int minDistance(string word1, string word2) {
        int lcs = 0;
        int n = word1.size() + 1,m = word2.size() + 1;

        vector<vector<int>> v(n,vector<int>(m,0));
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(word1[i-1] == word2[j-1]){
                    v[i][j] = 1 + v[i-1][j-1];
                }

                else{
                    v[i][j] = max(v[i][j-1],v[i-1][j]);
                }
            }
        }

        lcs = v[n-1][m-1];
        n = n - 1;
        m = m - 1;

        return (m + n - 2*lcs);
    }
};