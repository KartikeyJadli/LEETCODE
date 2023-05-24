//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:

    bool check(int N){
        string str = to_string(N);
        int n = str.length();
        for(int i=n-1;i>=0;i--){
            if(str[i] < str[i-1]){
                return false;
            }
        }
        
        return true;
    }
    
    int find(int N){
        // code here
        while(N > 0){
            if(check(N)){
                return N;
            }
            
            N = N - 1;
        }
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.find(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends