class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n);
        int pos1 = 0,pos2 = 1;
        for (int i=0;i<n;i++) {
            if(nums[i] % 2 == 0){
                v[pos1] = nums[i];
                pos1 += 2;
            }

            else {
                v[pos2] = nums[i];
                pos2 += 2;
            }
        }

        return v;
    }
};