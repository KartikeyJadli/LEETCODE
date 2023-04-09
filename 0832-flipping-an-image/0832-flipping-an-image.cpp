class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size();
        vector<vector<int>> v;
        for(int i=0;i<n;i++){
            vector<int> v1;
            for(int j=n-1;j>=0;j--){
                v1.push_back(image[i][j]);
            }

            v.push_back(v1);
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j] == 1){
                    v[i][j] = 0;
                }

                else{
                    v[i][j] = 1;
                }
            }
        }

        return v;
    }
};