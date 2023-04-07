class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> v;
        int n = nums.size();

        for(int i=0;i<n;i++){
            if(nums[i] < 10){
                v.push_back(nums[i]);
            }

            else{
                string str = to_string(nums[i]);
                for(int j=0;j<str.length();j++){
                    v.push_back(str[j] - '0');
                }
            }
        }

        return v;
    }
};