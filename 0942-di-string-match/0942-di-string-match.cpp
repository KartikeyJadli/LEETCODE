class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.length();
        vector<int> v;
        int mx = n,mn = 0;

        for(int i=0;i<n;i++){
            if(s[i] == 'I'){
                v.push_back(mn++);
            }

            else{
                v.push_back(mx--);
            }
        }

        if(s.back() == 'I'){
            v.push_back(mn);
        }

        else{
            v.push_back(mx);
        }

        return v;
    }
};