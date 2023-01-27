class Solution {
public:
    int issq(int n){
        int n1 = 0,n2 = 100;
        long long int sum = 0;

        while(n != 0){
            n1 = n % 10;
            sum = sum + n1*n1;
            n = n/10;
        }

        return sum;
    }

    bool isHappy(int n) {
        while(n > 9){
            n = issq(n);
        }
    
        if(n == 1 || n == 10 || n == 7){
            return true;
        }

        return false;
    }
};