class Solution {
private:
    map<pair<int,int>, int> mp;
public:
    int longestPalindromeSubseq(string s){
        return longestPalindromeSubseq(s,0,s.size()-1);
    }
    int longestPalindromeSubseq(string s, int i, int j) {
        int len = s.size();
        int res = 1;
        if(len <=1 )
            return len;
        pair<int,int> tp = make_pair(i,j);
        if(mp.find(tp)!=mp.end())
            return mp[tp];
        
        int cur = i, curj = j;
        vector<bool> visited(26,false);
        for(;j>=cur+1;j--){
            if(visited[s[j] -'a'])
               continue; 
            i = cur;
            char ch = s[j];
            while(i<=j && s[i] != s[j])
                i++;
            if(j - i <= 2)
                res = max(res, j-i+1);
            else
                res = max(res, longestPalindromeSubseq(s,i+1,j-1) + 2);
            visited[ch-'a'] = true;
        }
        mp[tp] = res;
        return res;
    }
};