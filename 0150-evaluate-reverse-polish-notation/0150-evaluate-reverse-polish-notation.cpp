class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>s;

        for(int i=0;i<tokens.size();i++){
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                s.push(stoi(tokens[i]));
            }

            else{
                long long int operation = s.top();
                s.pop();
                
                if(tokens[i] == "+")
                    s.top() += operation;
                
                else if(tokens[i] == "-")
                    s.top() -= operation;
                
                else if(tokens[i]=="*")
                    s.top() *= operation;
                
                else if(tokens[i]=="/")
                    s.top() /= operation;
            }
        }

        return s.top();
    }
};