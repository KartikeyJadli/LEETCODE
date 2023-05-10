class Solution {
public:
    int maxDepth(string s) {
        int mx = 0,count = 0;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                count++;
            }

            else if(s[i] == ')'){
                count--;
            }

            mx = max(mx,count);
        }

        return mx;
    }
};