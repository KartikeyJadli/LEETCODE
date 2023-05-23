//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        int i = 0,j = 0,k = n - 1;
        for(int l=0;l<n;l++){
            if(a[j] == 1){
                j++;
            }
            
            else if(a[j] == 0){
                swap(a[i],a[j]);
                j++;
                i++;
            } 
            
            else if(a[j] == 2){
                swap(a[j],a[k]);
                // j++;
                k--;
            }
        }
        
        return;
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends