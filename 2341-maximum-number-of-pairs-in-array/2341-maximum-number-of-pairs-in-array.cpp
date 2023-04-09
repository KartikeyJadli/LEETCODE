class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        vector<int> v(101,0);
        vector<int> v1;
        int n = nums.size(),count = 0,diff = 0;

        for(int i=0;i<n;i++){
            v[nums[i]]++;
        }

        for(int i=0;i<101;i++){
            if(v[i] > 0){
                diff += v[i] % 2;
                count += v[i]/2;
            }
        }

        v1.push_back(count);
        v1.push_back(diff);

        return v1;
    }
};