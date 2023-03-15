class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        stringstream str1,str2;
        long long n = numerator,d = denominator,quo = n/d,rem = n % d;

        if (quo == 0 && ((n > 0 && d < 0) || (n < 0 && d > 0))){
            str1 << '-';
        }

        str1 << quo;
        if(rem){
            str1 << ".";
        }  

        unordered_map<long long,int> mp;
        int i = 0;
        if(rem < 0 ){
            rem = -rem;
        }

        if(d < 0 ){
            d = -d;
        }

        while(rem){
            n = rem * 10;
            if (mp.find(n) == mp.end()){
                quo = n / d;
                rem = n % d;
                str2 << quo;
                mp[n] = i++;
            } 

            else {
                return str1.str() + str2.str().substr(0,mp[n]) + '(' + str2.str().substr(mp[n]) + ')';
            }
        }

        return str1.str() + str2.str();
    }
};