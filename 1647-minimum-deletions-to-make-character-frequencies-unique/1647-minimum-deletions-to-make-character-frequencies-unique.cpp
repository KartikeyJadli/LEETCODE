class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26,0);
        int n = s.length();

        for(int i=0;i<n;i++){
            v[s[i] - 'a']++;
        }

        sort(v.begin(),v.end());
        int count = 0;

        for(int i=0;i<25;i++){
            if(v[i] == v[i+1] && v[i] != 0){
                count++;
                v[i]--;
                i = 0;
            }
        }

        return count;
    }
};