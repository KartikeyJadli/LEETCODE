class Solution {
public:
    int tribonacci(int n) {
        if(n < 2){
            return n;
        }

        int x = 0,y = 1,z = 1,sum;
        
        while(n > 2){
            sum = x + y + z;
            x = y;
            y = z;
            z = sum;
            n--;
        }

        return z;
    }
};