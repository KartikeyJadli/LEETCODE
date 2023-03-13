const int mod = 1e9 + 7;
const int mxx = 1e5 + 1;
#define ll long long
class Solution {
public:
    vector<int> a, b;
    
    Solution(){
        a.resize(mxx, 0);
        a[1] = 1;
        a[2] = 2;
        a[3] = 4;
        
        for(int i=4; i<=1e5; i++){
            a[i] = ((a[i-1] + a[i-2]) % mod + a[i-3]) % mod;
        }
        
        b.resize(mxx, 0);
        b[1] = 1;
        b[2] = 2;
        b[3] = 4;
        b[4] = 8;
        
        for(int i=5; i<=1e5; i++)
        {
            b[i] = ((((b[i-1] + b[i-2]) % mod + b[i-3]) % mod) + b[i-4]) % mod;
        }
    }
    
    int countTexts(string s) {
        int n = s.size();
        int ans = 1;
        
        int cnt = 1;
        int i = 0;
        while(i+1 < n){
            while(i+1 < n && s[i] == s[i+1]) {
                cnt++;
                i++;
            }
            // cout << a[cnt] << " ";
            if(s[i] != '7' && s[i] != '9')
                ans = ((ll)ans * (ll)a[cnt]) % mod;
            else
                ans = ((ll)ans * (ll)b[cnt]) % mod;
            
            cnt = 1;
            i++;
        }

        return ans;
    }
};