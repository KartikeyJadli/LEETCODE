class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> v;
        int idx = 0;
        for (int i=1;i<=n;i++){
            if (idx == target.size()){
                break;
            }

            if (i == target[idx]){
                v.push_back("Push");
                idx++;
            } 
            
            else {
                v.push_back("Push");
                v.push_back("Pop");
            }
        }
        
        return v;
    }
};