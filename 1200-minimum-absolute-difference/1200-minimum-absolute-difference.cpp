class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> v;
        sort(arr.begin(),arr.end());
        int n = arr.size();
        int m = abs(arr[0] - arr[1]);

        for(int i=1;i<n-1;i++){
            m = min(m,abs(arr[i] - arr[i+1]));
        }

        for(int i=0;i<n-1;i++){
            if(m == abs(arr[i] - arr[i+1])){
                v.push_back({arr[i],arr[i+1]});
            }
        }

        return v;
    }
};