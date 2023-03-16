class Solution {
public:
    bool checkValidString(string s) {
        int open = 0,close = 0,n = s.length();

        for(int i=0;i<n;i++){
            if(s[i] == '('){
                open++;
                close++;
            }

            else if(s[i] == ')'){
                open--;
                close--;
            }

            else{
                open--;
                close++;
            }

            if(close < 0){
                return false;
            }

            if(open < 0){
                open = 0;
            }
        }

        return open == 0;
    }
};