class Solution {
public:
    int addDigits(int num) {
        string str = to_string(num);
        int n = str.size();
        
        if(n == 1){
            return num;
        }

        return num % 9 == 0 ? 9: num%9;
    }
};