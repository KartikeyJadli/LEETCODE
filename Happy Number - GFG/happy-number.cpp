//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int isHappy(int N){
        // code here
        int num = N;
        while(num > 9){
            int temp = 0;
            while(num > 0){
                int rem = num % 10;
                num /= 10;
                temp += rem * rem;
            }
            
            num = temp;
        }
        
        if(num == 1 || num == 7){
            return 1;
        }
        
        return 0;
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
        cout << ob.isHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends