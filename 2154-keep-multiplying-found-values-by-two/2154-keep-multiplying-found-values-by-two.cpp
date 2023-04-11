class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int> s;

        for(auto x: nums){
            s.insert(x);
        }

        int n = s.size(); 
        while(1){
            auto it = s.find(original);
            if(it != s.end()){
                original = original * 2;
            }

            else{
                break;
            }
        }

        return original;
    }
};