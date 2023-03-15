class Solution {
public:
    string strWithout3a3b(int a, int b) {
        if(a == 0){
            return string(b,'b');
        }

        else if(b == 0){
            return string(a,'a');
        }

        else if(a == b){
            return "ab" + strWithout3a3b(a-1,b-1);
        }

        else if(a > b){
            return "aab" + strWithout3a3b(a-2,b-1);
        }

        else{
            return strWithout3a3b(a-1,b-2) + "abb";
        }
    }
};