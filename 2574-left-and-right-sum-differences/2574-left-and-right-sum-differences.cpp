class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& nums) {
        if(nums.size() == 1){
            return {0};
        }

        vector<int> v,leftSum,rightSum(nums.size(),0);
        int n = nums.size(),sum = 0;
        leftSum.push_back(0);
        for(int i=1;i<n;i++){
            leftSum.push_back(leftSum[i-1] + nums[i-1]);
        }

        rightSum[n - 1] = 0;
        sum += nums[n-1];
        for(int i=n-2;i>=0;i--){
            rightSum[i] = sum;
            sum += nums[i];
        }

        for(int i=0;i<n;i++){
            v.push_back(abs(leftSum[i] - rightSum[i]));
        }

        return v;
    }
};