class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size() < nums2.size()){
            swap(nums1, nums2);
        }

        int m = nums1.size(), n = nums2.size();
        vector<int> dp(n + 1, 0);
        int prev;
        for(int i=1;i<m+1;i++) {
            prev = 0;
            for (int j = 1; j < n + 1; ++j) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    int tmp = dp[j];
                    dp[j] = prev + 1;
                    prev = tmp;
                }

                else {
                    prev = dp[j];
                    dp[j] = max(dp[j], dp[j - 1]);
                }
            }
        }
        
        return dp[n];
    }
};