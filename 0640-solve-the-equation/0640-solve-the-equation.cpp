class Solution {
public:
    string solveEquation(string equation) {
        int cff = 0,val = 0,lside = 1,sign = 1;
        char ch;
        stringstream ss(equation);
        while(ss.peek() > 0){
            int num = 0;
            if(isdigit(ss.peek())){
                ss >> num;
                if(num == 0 && ss.peek() == 'x'){
                    ss >> ch;
                }
            }

            else if(ss.peek() == '+'){
                ss >> ch;
                sign = 1;
            }

            else if(ss.peek() == '-'){
                ss >> ch;
                sign = -1;
            }

            else if(ss.peek() == '='){
                ss >> ch;
                lside = -1;
                sign = 1;
            }
            
            if(ss.peek() == 'x'){
                cff += lside * sign * max(num,1);
                ss >> ch;
            }
            
            else{
                val += lside * sign * num;
            }
        }

        if(cff != 0){
            return string("x=") + to_string(-val/cff);
        }

        if(cff == 0 && val == 0){
            return "Infinite solutions";
        }

        return "No solution";     
    }
};