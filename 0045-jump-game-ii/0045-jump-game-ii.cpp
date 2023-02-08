class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() < 2)
            return 0;
        int n = nums.size();
        
        vector<int> v(n,0);
        
        for(int i=n-2;i>=0;i--){
            int m = INT_MAX - 1;
            
            for(int j=1;j<=min(n-1-i,nums[i]);j++){
                int t = 1 + v[i+j];
                m = min(m,t);
            }
            
            v[i] = m;
        }
        
        return v[0];
    }
};