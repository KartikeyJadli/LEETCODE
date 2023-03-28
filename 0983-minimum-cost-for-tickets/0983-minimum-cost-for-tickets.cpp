
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        if (days.empty()) {
            return 0;
        } 
        
        int n = days.back();
        unordered_set<int> daysSet(days.begin(), days.end());
        vector<int> dp(n + 1, INT_MAX);
        
        dp[0] = 0;
        
        for (int i=1;i<=n;i++) {
            if (daysSet.count(i) == 0) {
                dp[i] = dp[i - 1];
            }
            
            else {
                dp[i] = dp[i - 1] + costs[0];
                
                int j = max(0, i - 7);
                dp[i] = min(dp[i], dp[j] + costs[1]);
        
                j = max(0, i - 30);
                dp[i] = min(dp[i], dp[j] + costs[2]);
            }
        }
        
        return dp[n];
    }
};