class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> m;
        int temp = 0, count = 0;
        for (string w: words){
            if(w[0] == w[1]){
                if(m[w] > 0){
                    temp--;
                    m[w]--;
                    count += 4;
                }

                else{
                    m[w]++;
                    temp++;
                }
            }

            else{
                string rev = w;
                reverse(rev.begin(), rev.end());
                if (m[rev] > 0) {
                    count += 4;
                    m[rev]--;
                }

                else{
                    m[w]++;
            
                }
            }
        }

        if(temp > 0){
            count += 2;
        }
        
        return count;
    }
};