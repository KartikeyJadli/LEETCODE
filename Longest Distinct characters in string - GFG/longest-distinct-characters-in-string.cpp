//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string s)
{
    // your code here
    vector<int>v(26,0);
    int l = 0,r = 0,count = 0,res = 0;
    
    while(r < s.size()){
        if(v[s[r] - 'a'] == 0){
            res=max(res,++count);
            v[s[r]-'a']=1;
            r++;
        }
        
        else{
            l++;
            r=l;
            v.assign(26,0);
            count=0;
        }
    }
    
    return res;
    
}