class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int n = nums.size();
        for(long long i=0; i<n; i++) {
            long long Lower = lower_bound(nums.begin(), nums.end(), lower-nums[i]) - nums.begin();
            long long Upper = upper_bound(nums.begin(), nums.end(), upper-nums[i]) - nums.begin();
            Lower = max(Lower, i+1);
            if(Upper >= Lower){
                ans += Upper - Lower;
            }
                
            else{
                break;
        
            }
        }
        
        return ans;
    }
};