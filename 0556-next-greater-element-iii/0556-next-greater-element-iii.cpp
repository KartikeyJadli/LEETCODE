class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        vector<int> v;
        
        next_permutation(s.begin(),s.end());
        
        string a = s;
        
        prev_permutation(a.begin(),a.end());
        
        if(s <= a)
            return -1;
        
        long long ans = 0;
        for(int i=0;i<s.size();i++){
            ans = ans + pow(10,s.size()-i-1) * (s[i]-'0');
        }
        
        if(ans > INT_MAX or ans < INT_MIN)
            return -1;
        
        return ans;
    }
};