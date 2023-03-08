class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        string str = "",str1 = "";
        if(n <= 1){
            return s;
        }

        vector<int> v(26,0);

        for(int i=0;i<n;i++){
            v[s[i] - 'a']++;
        }

        int j = 0;
        for(int i=0;i<n;i++){
            if(s[j] > s[i]){
                j = i;
            }

            if(!--v[s[i] - 'a']){
                break;
            }
        }

        for(int i=j+1;i<n;i++){
            if(s[i] == s[j]){
                continue;
            }

            str += s[i];
        }

        str1 += s[j];

        return str1 + removeDuplicateLetters(str);
    }
};