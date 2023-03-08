class Solution {
public:
    string decodeString(string s) {
        string decoded = "", num = "";
        for (i;i<s.length(); i++) {
            if (isDigit(s[i])) {
                while(isDigit(s[i])) {
                    num += s[i++];
                }
                i++;
                int times = stoi(num);
                string temp = decodeString(s);
                for (int i = 1; i <= times; i++) {
                    decoded += temp;
                }
                num = "";
            }
            else if (s[i] == ']') {
                return decoded;
            }

            else {
                decoded += s[i];
            }
        }

        return decoded;
    }

    int i = 0;
    bool isDigit(char c) {
        return c - '0' >= 0 && c - '0' <= 9;
    }
};