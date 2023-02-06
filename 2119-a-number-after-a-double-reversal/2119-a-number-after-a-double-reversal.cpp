class Solution {
public:
    bool isSameAfterReversals(int num) {
        int sum1 = 0;
        int rem,n = num;

        if(num < 10){
            return true;
        }

        if(num % 10 == 0){
            return false;
        }

        while(n != 0){
            rem = n % 10;
            sum1 = sum1 * 10 + rem;
            n = n/10;
        }

        n = sum1;
        sum1 = 0;

        while(n != 0){
            rem = n % 10;
            sum1 = sum1 * 10 + rem;
            n = n/10;
        }

        return num == sum1;
    }
};