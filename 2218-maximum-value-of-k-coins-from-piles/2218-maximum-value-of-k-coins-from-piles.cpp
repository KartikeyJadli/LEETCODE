class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int N = piles.size(), m[1001][2001] = {};
        memset(m, -1, sizeof(m));
        function<int(int, int)> dp =[&](int i, int j) {
            if(m[i][j] != -1){
                return m[i][j];
            }

            if(i == N){
                return 0;
            }

            int ans = dp(i + 1, j), sum = 0;
            for (int t=1;t<=j && t<=piles[i].size();t++) {
                sum += piles[i][t - 1];
                ans = max(ans, dp(i + 1, j - t) + sum);
            }

            return m[i][j] = ans;
        };
        
        return dp(0, k);
    }
};