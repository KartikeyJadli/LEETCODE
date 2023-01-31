class Solution {
public:
    string interpret(string command) {
        string str = "";

        for(int i=0;i<command.length();i++){
            if(command[i] == 'G'){
                str.push_back(command[i]);
            }

            else if(command[i] == '(' && command[i+1] == ')'){
                str.push_back('o');
            }

            else if(command[i] == '(' && command[i+1] == 'a' && command[i+2] == 'l' && command[i+3] == ')'){
                str.push_back('a');
                str.push_back('l');
                i += 3;
            }
        }

        return str;
    }
};