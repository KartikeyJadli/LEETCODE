class Solution {
public:
    int DFS(vector<int> &satisfaction,vector<vector<int>> &v,int z,int o){
        if(z >= satisfaction.size()){
            return 0;
        }

        if(v[z][o]){
            return v[z][o];
        }

        return v[z][o] = max(DFS(satisfaction,v,z+1,o),satisfaction[z] * o + DFS(satisfaction,v,z+1,o+1));
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        vector<vector<int>> v(501,vector<int> (501));
        sort(satisfaction.begin(),satisfaction.end());

        return DFS(satisfaction,v,0,1);
    }
};