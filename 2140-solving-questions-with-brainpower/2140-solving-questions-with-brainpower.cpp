class Solution {
public:
    long long max(long long a,long long b){
        return a > b ? a : b;
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1,0);
        long long result = 0;
        for(long long i=1;i<=n;i++){
            int length = questions[i-1][1];
            if(i + 1 <= n){
                dp[i+1] = max(dp[i],dp[i+1]);
            }

            if(i + length + 1 <= n){
                dp[i+length+1] = max(dp[i]+questions[i-1][0],dp[i+length+1]);
            }

            result = max(result,dp[i]+questions[i-1][0]);
        }
        
        return result;
    }
};