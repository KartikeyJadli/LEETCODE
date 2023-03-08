class Solution {
public:
    bool canConvertString(string s, string t, int k) {
        int n = s.length();
        int m = t.length();

        if(n != m){
            return false;
        }

        vector<int> v(27);
        for(int i=0;i<27;i++){
            v[i] = i;
        }

        for(int i=0;i<n;i++){
            if(s[i] != t[i]){
                int shift = (t[i] - s[i] + 26) % 26;
                
                if(v[shift] > k){
                    return false;
                }

                v[shift] += 26;
            }
        }

        return true;
    }
};