class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        int i = 0,j = 0;
        int mx;
        string str = "";
        
        while(i < n || j < m){
            if(i < n){
                str.push_back(word1[i]);
                i++;
            }

            if(j < m){
                str.push_back(word2[j]);
                j++;
            }
        }
        
        return str;
    }
};