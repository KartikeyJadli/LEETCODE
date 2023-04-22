class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        vector <vector<int>> dp(n + 1, vector <int>(n + 1,0));
        
        for(int i = 1; i < n; ++i)
            for(int j = 0; j < n - i; ++j){
                if(s[i + j] == s[j])
                    dp[j][i + j] = dp[j + 1][i + j - 1];
                else
                    dp[j][i + j] = min(dp[j + 1][i + j], dp[j][i + j - 1]) + 1;
            }
        
        return dp[0][n - 1];
    }
};