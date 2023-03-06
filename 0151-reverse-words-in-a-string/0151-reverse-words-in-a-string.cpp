class Solution {
public:
    string reverseWords(string s) {
        string str = "";
        int n = s.length(),i = 0;

        while(i < n){
            while(i < n && s[i] == ' '){
                i++;
            }

            if(i >= n){
                break;
            }

            int j = i + 1;
            while(j < n && s[j] != ' '){
                j++;
            }

            string str1 = s.substr(i,j-i);
            if(str.length() == 0){
                str = str1;
            }

            else{
                str = str1 + " " + str;
            }

            i = j + 1;
        }

        return str;
    }
};