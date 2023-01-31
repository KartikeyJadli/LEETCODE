class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        const int n = scores.size();
        vector<int> dp(n, 0);
    
        vector<pair<int, int>> arr(n, {0, 0}); 
        for(int i = 0; i < n;i++){
            arr[i].first = ages[i];
            arr[i].second = scores[i];
        }

        sort(arr.begin(), arr.end());
        int team_score = 0;
        
        for(int i = 0; i < n;i++){
            dp[i] = arr[i].second;
            for(int j = i - 1; j >= 0;j--){
                if(arr[i].second >= arr[j].second){
                    dp[i] = max(dp[i], dp[j] + arr[i].second); 
                }
            }
        
            team_score = max(team_score, dp[i]); 
        }

        return team_score;
    }
};