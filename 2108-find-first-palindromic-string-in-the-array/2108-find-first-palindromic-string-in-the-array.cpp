class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        int n = words.size();

        for(int i=0;i<n;i++){
            string str = words[i];
            reverse(str.begin(),str.end());
            if(str == words[i]){
                return words[i];
            }
        }

        return "";
    }
};