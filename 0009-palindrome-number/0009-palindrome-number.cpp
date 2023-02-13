class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0){
            return false;
        }

        long long int sum = 0;
        int num = x,rem;
        while(x != 0){
            rem = x % 10;
            sum = sum * 10 + rem;
            x = x/10;
        }

        cout << sum;

        return num == sum;
    }
};