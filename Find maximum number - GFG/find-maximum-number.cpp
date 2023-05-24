//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    string findMax(string N) {
        // code here
        int freq[10] = {0};
        int n = N.length();
        
        for(int i=0;i<n;i++){
            freq[N[i] - '0']++;
        }
        
        N.clear();
        for(int i=9;i>=0;i--){
            while(freq[i] > 0){
                N += (i + '0');
                freq[i]--;
            }
        }
        
        return N;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string N;
        
        cin>>N;

        Solution ob;
        cout << ob.findMax(N) << endl;
    }
    return 0;
}
// } Driver Code Ends