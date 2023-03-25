class Solution {
public:
    int countAsterisks(string s) {
        int count = 0,temp = 0,n = s.length();

        for(int i=0;i<n;i++){
            if(s[i] == '|' && temp == 0){
                temp++;
            }

            else if(s[i] == '|' && temp > 0){
                temp--;
            }

            else if(s[i] == '*' && temp == 0){
                count++;
            }
        }

        return count;
    }
};