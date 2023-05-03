class Solution {
public:
    int reverse(int n){
        int num = 0;
        while(n){
            num = num * 10 + (n % 10);
            n = n/10;
        }

        return num;
    }

    int countNicePairs(vector<int>& nums) {
        map<int,int> mp;
        long long x = 0,count = 0,MOD = 1e9+7;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int d = nums[i] - reverse(nums[i]);
            x = mp[d]++;

            if(x){
                count += x;
            }
        }

        return count % MOD;
    }
};