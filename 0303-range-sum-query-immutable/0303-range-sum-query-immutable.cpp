class NumArray {
public:
    vector<int> v;
    NumArray(vector<int>& nums) {
        for(auto &x: nums){
            v.push_back(x);
        }
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        if(left == right){
            return v[left];
        }

        for(int i=left;i<=right;i++){
            sum += v[i];
        }

        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */