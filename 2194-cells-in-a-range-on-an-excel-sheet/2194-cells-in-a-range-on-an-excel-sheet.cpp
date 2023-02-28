class Solution {
public:
    vector<string> cellsInRange(string s) {
        char c = s[0], d = s[3];
        char a = s[1];
        char b = s[4];

        vector<string> v;
        for(char i=c;i<=d;i++) {
            for(char j = a; j <= b; j++) {
                string str;
                str += i;
                str += j;
                v.push_back(str);
            }
        }   

        return v;
    }
};