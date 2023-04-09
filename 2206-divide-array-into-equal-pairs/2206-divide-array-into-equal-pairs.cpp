class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(501,0);

        for(int i=0;i<n;i++){
            v[nums[i]]++;
        }

        for(int i=0;i<501;i++){
            if(v[i] % 2 != 0){
                return false;
            }
        }

        return true;
    }
};