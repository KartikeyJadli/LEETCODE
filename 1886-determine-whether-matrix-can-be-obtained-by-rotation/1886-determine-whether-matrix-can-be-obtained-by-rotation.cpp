class Solution {
public:
    vector<vector<int>> rotate(vector<vector<int>>& image) {
        for (int i = 0; i < image.size();i++){
            for (int j = i; j < image.size();j++){
                swap(image[i][j], image[j][i]);
            }
        }

        for(int i=0;i<image.size();i++){
            reverse(image[i].begin(),image[i].end());
        }

        return image;
    }

    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat == target){
            return true;
        }

        if(rotate(mat) == target){
            return true;
        }

        if(rotate(mat) == target){
            return true;
        }

        if(rotate(mat) == target){
            return true;
        }
        
        return false;
    }
};