//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
string transform(string s);

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        cout << transform(s) << endl;
    }
return 0;
}


// } Driver Code Ends


string transform(string S){
    //complete the function here
    int count = 1;
    int n = S.length();
    transform(S.begin(),S.end(),S.begin(),::tolower);
    // cout << S << endl;
    string str = "";
    for(int i=0;i<=n-1;i++){
        if(S[i] == S[i+1]){
            count++;
        }
        
        else{
            str += to_string(count);
            str += S[i];
            count = 1;
        }
    }
    
    return str;
}

