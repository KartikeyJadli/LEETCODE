class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long result = 0;
        
        int i = 0,j = nums.size() - 1;
        
        while(i < j){
            string str = to_string(nums[i++]) + to_string(nums[j--]);
            long long temp = stol(str);
            result += temp;
        }
        
        if(nums.size() % 2 == 1){
            result += nums[j];
        }
        
        return result;
    }
};