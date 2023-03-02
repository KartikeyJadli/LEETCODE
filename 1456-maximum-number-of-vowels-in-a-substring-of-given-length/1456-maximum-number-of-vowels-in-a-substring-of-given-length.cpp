class Solution {
public:
    int maxVowels(string s, int k) {
        set<char> st = {'a','e','i','o','u'};
        int i = 0,j = 0;

        int count = 0,mx = 0;

        while(j != k){
            if(st.count(s[j])){
                count++;
            }

            j++;
        }

        j--;
        mx = count;

        while(j != s.size()){
            if(st.count(s[i]) && count > 0){
                count--;
            }

            i++;
            j++;

            if(st.count(s[j])){
                count++;
            }

            mx = max(mx,count);
        }

        return mx;
    }
};