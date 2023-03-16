class Solution {
public:
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int low = 0,high = removable.size(),count = 0;

        while(low <= high){
            int mid = low + (high - low)/2;
            string str = s;
            for(int i=0;i<mid;i++){
                str[removable[i]] = 'A';
            }

            int n = p.length(),j = 0;
            for(int i=0;i<str.size()&&j<n;i++){
                if(str[i] == p[j]){
                    j++;
                }
            }

            if(n == j){
                count = mid;
                low = mid + 1;
            }

            else{
                high = mid - 1;
            }
        }

        return count;
    }
};