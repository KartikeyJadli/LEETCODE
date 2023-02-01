class Solution {
public:
    bool isThree(int n) {
        int count = 0;

        for(int i=1;i<=sqrt(n);i++){
            if(n % i == 0){
                count++;
                if(n / i != i){
                    count++;
                }
            }

            if(count > 3){
                return false;
            }
        }

        return count == 3;
    }
};