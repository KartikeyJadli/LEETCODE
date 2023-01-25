class Solution {
public:
    double myPow(double x, int n) {
         double res = 1;
        
        if (n < 0){
            return 1 / x * myPow(1 / x, - (n + 1));
        }
        
        while(n){
            if(n % 2 == 0){
                x *= x;
                n = n/2;
            }
            
            else{    
                res *= x;
                n--;
            }
        }
        
        return res;
    }
};