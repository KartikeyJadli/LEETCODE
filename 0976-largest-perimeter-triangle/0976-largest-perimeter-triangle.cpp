class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        int peri = 0;
        sort(nums.begin(),nums.end());
        
        for(int i=nums.size()-1;i>=2;i--){
            if(nums[i-1] + nums[i-2] > nums[i]){
                peri = nums[i-1] + nums[i-2] + nums[i];
                return peri;
            }
        }
        
        return peri;
    }
};