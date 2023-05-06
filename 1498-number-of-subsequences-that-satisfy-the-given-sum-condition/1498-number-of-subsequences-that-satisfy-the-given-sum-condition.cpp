class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int MOD = 1e9 + 7;
        sort(nums.begin(),nums.end());
       
        int low = 0,high = nums.size() - 1,count = 0;
        vector<int> v(high+1,1);
        for(int i=1;i<=high;i++){
            v[i] = (v[i-1] * 2) % MOD;
        }

        while(low <= high){
            if(nums[low] + nums[high] > target){
                high--;
            }

            else{
                count = (count + v[high - low++]) % MOD;
            }
        }

        return count;
    }
};