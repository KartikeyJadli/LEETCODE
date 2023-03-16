class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s3.size() != (s1.size() + s2.size()))
		return 0;
        int row = s1.length(),col = s2.length();
        vector<int> v(col + 1,0);
        vector<vector<int>> v1(row + 1,v);
        v1[0][0] = 1;

        for(int i=0;i<=row;i++){
            for(int j=0;j<=col;j++){
                if(i > 0 && v1[i - 1][j]){
                    if(s1[i - 1] == s3[i + j - 1]){
                        v1[i][j] = 1;
                    }
                }

                if (j > 0 && v1[i][j - 1]){
                    if (s2[j - 1] == s3[i + j - 1]){
                        v1[i][j] = 1;
                    }
                }
            }
        }

        return v1[row][col];
    }
};