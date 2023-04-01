class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int esum = 0,dsum = 0;
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            esum += nums[i];
        }

        for(int i=0;i<n;i++){
            if(nums[i] > 10){
                int temp = nums[i];
                while(temp != 0){
                    dsum += temp%10;
                    temp = temp/10;
                }
            }

            else if(nums[i] == 10){
                dsum += 1;
            }

            else{
                dsum += nums[i];
            }
        }

        return abs(esum - dsum);
    }
};