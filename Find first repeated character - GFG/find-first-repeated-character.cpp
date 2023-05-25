//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string s)
{
    //code here.
    map<char,int> mp;
    string str = "";
    for(auto x: s){
        if(mp.find(x) != mp.end()){
            str += x;
            return str;
        }
        
        mp[x]++;
    }
    
    return "-1";
}