class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        int n = items1.size();
        int m = items2.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(items1[i][0] == items2[j][0]){
                    items1[i][1] += items2[j][1];
                    items2[j][1] = -1;
                }
            }
        }

        for(int i=0;i<m;i++){
            if(items2[i][1] != -1){
                items1.push_back(items2[i]);
            }
        }

        sort(items1.begin(),items1.end());
        return items1;
    }
};