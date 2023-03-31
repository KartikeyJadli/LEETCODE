class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        int j = n - 1;
        
        for(int i=0;i<n;i++){
            swap(s[i],s[j]);
            j--;

            if(i >= j){
                break;
            }
        }
    }
};