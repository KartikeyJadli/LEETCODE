class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0,n = words.size();
        for(int i=0;i<n;i++){
            string str = words[i];
            int temp = str.size();

            if(str[0] == s[0]){
                if(s.substr(0,temp) == str){
                    count++;
                }
            }
        }

        return count;
    }
};