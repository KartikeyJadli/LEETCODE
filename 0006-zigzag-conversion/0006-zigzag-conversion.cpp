class Solution {
public:
    string convert(string s, int numRows){
        if(numRows == 1){
            return s;
        }

        string str;
        int n = s.length();
        int m = 2 * (numRows - 1);

        for(int i=0;i<numRows;i++){
            int temp = i;

            while(temp < n){
                str += s[temp];

                if(i != 0 && i != numRows - 1){
                    int n1 = m - 2 * i;
                    int n2 = temp + n1;

                    if(n2 < n){
                        str += s[n2];
                    }
                }

                temp += m;
            }
        }

        return str;
    }
};