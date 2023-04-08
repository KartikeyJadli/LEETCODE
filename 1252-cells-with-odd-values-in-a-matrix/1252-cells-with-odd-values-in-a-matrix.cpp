class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;

        for(auto x: indices){
           mp1[x[0]]++;
           mp2[x[1]]++;
        }
        
        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((mp1[i] + mp2[j]) % 2){
                    count++;
                }
            }
        }

        return count;
    }
};