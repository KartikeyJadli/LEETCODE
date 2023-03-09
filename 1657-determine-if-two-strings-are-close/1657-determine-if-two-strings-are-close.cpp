class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.length(),m = word2.length();
        if(n != m){
            return false;
        }
        
        set<char> s,st;
        vector<int> freq1(26,0),freq2(26,0);   
        for(int i=0;i<n;i++){
            s.insert(word1[i]);
            st.insert(word2[i]);
            freq1[word1[i] - 'a']++;
            freq2[word2[i] - 'a']++;
        }
        
        sort(freq1.begin(),freq1.end());
        sort(freq2.begin(),freq2.end());
        
        if(s == st && freq1 == freq2){
            return true;
        }
        
        else{
            return false;
        }
    }
};