class Solution {
public:
    bool check(vector<int> arr, int n) { 
        if (n == 1){ 
            return true;
        }
        
        sort(arr.begin(),arr.end());
        int d = arr[1] - arr[0]; 
        for (int i=2; i<n; i++){
            if (arr[i] - arr[i-1] != d){
                return false; 
            }
        }
    
        return true; 
    }

    vector<bool> checkArithmeticSubarrays(vector<int>& vec, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        vector<int> temp;
        for(int i = 0; i < l.size();i++){
            for(int j = l[i]; j < r[i]+1;j++){
                temp.push_back(vec[j]);
            }

            if(check(temp,temp.size()) == 1){
                ans.push_back(true);
            }

            else{
                ans.push_back(false);
            }
            temp.clear();
        }

        return ans;
    }
};