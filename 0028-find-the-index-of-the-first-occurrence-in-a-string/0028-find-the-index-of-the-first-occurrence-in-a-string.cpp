class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = needle.length();
        int m = haystack.length();

        for(int i=0;i<m;){
            if(needle == haystack.substr(i,n)){
                return i;
            }
            cout << i << " ";
            i += 1;
        }

        return -1;
    }
};