//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        // code here 
        vector<string> v;
        int n = S.length();
        string str = "";
        for(int i=0;i<n;i++){
            if(S[i] == '.'){
                v.push_back(str);
                str = "";
            }
            
            else{
                str += S[i];
            }
        }
        v.push_back(str);
        
        str = "";
        n = v.size();
        for(int i=n-1;i>=0;i--){
            str += v[i];
            str += ".";
        }
        
        str.pop_back();
        return str;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends