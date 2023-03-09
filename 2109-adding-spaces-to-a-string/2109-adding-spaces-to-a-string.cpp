class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int n = s.length(),m = spaces.size();
        string str = "";
        int i = 0,j = 0;

        while(i < n){
            if(j < m && i == spaces[j]){
                str += " ";
                j++;
            }

            else{
                str += s[i];
                i++;
            }
        }

        return str;
    }
};