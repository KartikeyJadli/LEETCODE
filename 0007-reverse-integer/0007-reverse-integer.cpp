class Solution {
public:
    int reverse(int x) {
        long int sum = 0;
        int rem;

        while(x != 0){
            rem = x % 10;
            sum = sum * 10 + rem;
            x = x/10;
        }

        if(sum >= INT_MIN && sum <= INT_MAX){
            return (int)sum;
        }

        return 0;
    }
};