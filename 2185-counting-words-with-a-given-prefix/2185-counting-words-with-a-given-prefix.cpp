class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        int m = pref.size(),count = 0;

        for(int i=0;i<n;i++){
            string str = words[i];
            if(str.substr(0,m) == pref){
                count++;
            }
        }

        return count;
    }
};