class Solution {
public:
    string generateTheString(int n) {
        string str = "";
        if(n % 2 == 1){
            for(int i=0;i<n;i++){
                str += 'a';
            }

            return str;
        }

        else{
            for(int i=0;i<n-1;i++){
                str += 'a';
            }

            str += 'b';

            return str;
        }
    }
};