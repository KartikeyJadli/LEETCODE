class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int gr = INT_MIN,n = arr.size();
        int temp = arr[n - 1];
        for(int i=n-1;i>0;i--) {            
            gr = max(gr, temp);
            temp = arr[i-1];
            arr[i-1] = gr;
        }

        arr[n - 1] = -1;

        return arr;
    }
};