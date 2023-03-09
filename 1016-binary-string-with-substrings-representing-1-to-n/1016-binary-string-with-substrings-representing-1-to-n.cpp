class Solution {
public:
    bool queryString(string s, int n) {
        vector<bool> v(n+1,false);
        int i = 0,j,m = s.length();

        while(i < m && s[i] == '0'){
            i++;
        }

        if(i > 0 && i < n){
            s = s.substr(i);
        }

        m = s.length();
        for(int i=0;i<m;i++){
            int temp = 0;
            for(int j=i;j<m;j++){
                temp <<= 1;
                temp += (s[j] - '0');

                if(temp > n){
                    break;
                }

                v[temp] = true;
            }
        }

        for(int i=1;i<=n;i++){
            if(!v[i]){
                return false;
            }
        }

        return true;
    }
};