class Solution {
public:
    int robber(vector<int>& nums, int l, int r) {
        int prev = 0,cur = 0;
        for (int i=l;i<=r;i++) {
            int temp = max(prev + nums[i], cur);
            prev = cur;
            cur = temp;
        }

        return cur;
    }

    int rob(vector<int>& nums) {
        int n = nums.size(); 
        if (n < 2){
            return n ? nums[0] : 0;
        }

        return max(robber(nums,0,n - 2), robber(nums,1,n - 1));
    }
};