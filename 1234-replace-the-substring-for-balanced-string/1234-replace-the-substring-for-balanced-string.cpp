class Solution {
public:
    int balancedString(string s) {
        map<char,int> mp;
        int n = s.length(),k = n/4;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        
        int i = 0,result = n;
        for(int j=0;j<n;j++){
            mp[s[j]]--;
            while(i-1<=j&&mp['W']<=k&&mp['E']<=k&&mp['Q']<=k&&mp['R']<=k){
                result = min(result,j-i+1);
                mp[s[i]]++;
                i++;
            }
        }
        
        return result;
    }
};