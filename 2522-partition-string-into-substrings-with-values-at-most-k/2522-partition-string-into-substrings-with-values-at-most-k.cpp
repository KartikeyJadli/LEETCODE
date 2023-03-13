class Solution {
public:
    int minimumPartition(string s, int k) {
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] - '0' > k){
                return -1; 
            }
        }

        int i = 0,count = 0;
        while(i < n) {
            int j = i;
            while(j < n){
                long int val = stol(s.substr(i, j - i + 1));
                if(j == n - 1 && val <= k){
                    count++;
                }
                
                j++;
                if(val > k) {
                    count++;
                    j--;
                    break;
                }
            }

            i = j;
        }
        
        return count;
    }
};