class Solution {
public:
    int minimumLength(string s) {
        int j = s.length() - 1,i = 0,count = s.length();
        cout << count << endl;
        if(s[0] != s[j]){
            return j + 1;
        }

        while(i < j){
            char ch = s[i];
            if(s[i] != s[j]){
                return (j - i + 1);
            }

            while(i < s.size() && s[i] == ch){
                i++;
            }

            while(j >= 0 && s[j] == ch){
                j--;
            }
        }

        if(i == j){
            return 1;
        }

        return 0;
    }
};