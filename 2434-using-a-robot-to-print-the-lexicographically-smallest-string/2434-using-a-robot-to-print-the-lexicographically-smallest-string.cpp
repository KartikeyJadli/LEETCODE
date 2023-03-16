class Solution {
public:
    string robotWithString(string s) {
        string str = "";
        string ans = "";
        int n = s.size();
        vector<char>mn(n);
        mn[n-1] = s[n-1];
        for(int i=n-2;i>=0;i--){
            if(s[i] < mn[i+1]){
                mn[i] = s[i];
            }
            
            else{
                mn[i] = mn[i+1];
            }
        }

        for(int i=0;i<n;i++){
            if(str.length() == 0 || str.back() > mn[i]){
                str += s[i];
            }

            else{
                while(str.size() > 0 && str.back() <= mn[i]){
                    ans += str.back();
                    str.pop_back();
                }

                str += s[i]; 
            }
        }

        while(str.size() > 0){
            ans += str.back();
            str.pop_back();
        }

        return ans;
    }
};