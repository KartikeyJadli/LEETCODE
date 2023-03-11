class Solution {
public:
    long long numberOfWays(string s) {
        int n = s.length();
        long long int a[n],b[n],p[n],suf[n],count = 0,result = 0;

        for(int i=0;i<n;i++){
            if(s[i] == '0'){
                count++;
            }

            p[i] = count;
        }

        count = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i] == '0'){
                count++;
            }

            suf[i] = count;
        }

        count = 0;
        for(int i=1;i<n-1;i++){
            if(s[i] == '1'){
                result += (p[i-1] * suf[i+1]);
            }
        }

        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                count++;
            }

            a[i] = count;
        }

        count = 0;
        for(int i=n-1;i>=0;i--){
            if(s[i] == '1'){
                count++;
            }

            b[i] = count;
        }

        for(int i=1;i<n-1;i++){
            if(s[i] == '0'){
                result += (a[i-1] * b[i+1]);
            }
        }

        return result;
    }
};