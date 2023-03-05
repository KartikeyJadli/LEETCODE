class Solution {
public:
    int calculate(string s) {
        int n = s.length();
        if(n == 0){
            return 0;
        }

        // if the string has 1 char and it is a digit, return as there are not other operations to be performed
        if(n == 1 && isdigit(s[0])){
            return stoi(s);
        }

        int current = 0,last = 0,result = 0;
        char op = '+';

        for(int i=0;i<n;i++){
            // if there is a 2 or more digit number like 25 or 100.
            if(isdigit(s[i])){
                current = (current * 10) + (s[i] - '0');
            }

            // iswspace() is a function for checking if the char is wide space or not
            if(!isdigit(s[i]) && !iswspace(s[i]) || i == n - 1){
                if(op == '+' || op == '-'){
                    result = result + last;
                    if(op == '+'){
                        last = current;
                    }
                    else{
                        last = -current;
                    }
                }

                else if(op == '*'){
                    last = last * current;
                }

                else if(op == '/'){
                    last = last/current;
                }

                op = s[i];
                current = 0;
            }
        }

        result = result + last;
        return result;
    }
};