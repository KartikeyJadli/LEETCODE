class Solution {
public:
    int partitionString(string s) {
        int flag = 0;
        int start = 0, end = 0, ans = 1;
        while(end < s.size()){
            if( flag & (1<<(s[end] - 'a'))) {
                flag = 0;
                ans++;
            }
            flag = flag | (1 << (s[end] - 'a'));
            end++;
        }
        
        return ans;
    }
};