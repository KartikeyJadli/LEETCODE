class Solution {
public:
    int arraySign(vector<int>& nums) {
        int count1 = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] < 0){
                count1++;
            }

            else if(nums[i] == 0){
                return 0;
            }
        }

        if(count1 % 2 == 0){
            return 1;
        }

        return -1;
    }
};