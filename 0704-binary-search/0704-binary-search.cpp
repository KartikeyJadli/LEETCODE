class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int a = binarysearch(nums,0,n-1,target);
        
        return a;
    }
    
    int binarysearch(vector<int> nums,int low,int high,int target){
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(nums[mid] == target){
                return mid;
            }
            
            else if(nums[mid] < target){
                return binarysearch(nums,mid+1,high,target);
            }
            
            else{
                return binarysearch(nums,0,mid-1,target);
            }
        }
        
        return -1;
    }
};