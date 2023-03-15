class Solution {
public:
    int minimumBuckets(string hamsters) {
        int totalBucket = 0;
        int n = hamsters.length();
        for(int i=0;i<n;) {
            if (hamsters[i] == 'H') {
                if(i + 1 < n && hamsters[i + 1] == '.') {
                    totalBucket++;
                    i += 3;
                } 

                else if (i - 1 >= 0 && hamsters[i - 1] == '.'){
                    totalBucket++;
                    i += 1;
                }

                else {
                    return -1;
                }
            } 

            else{
                i ++;
            }
        }

        return totalBucket;
    }
};