class Solution {
public:
    string replaceDigits(string s) {
        string str = "";
        int n = s.length();
        str += s[0];
        for(int i=1;i<n;i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                str += s[i];
            }

            else{
                str += ((s[i] - '0') + s[i-1]);
            }
        }

        return str;
    }
};