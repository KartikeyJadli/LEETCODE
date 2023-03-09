class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        unordered_map<string,int> mp;
        int temp = 0,n = favoriteCompanies.size();

        vector<vector<int>> v(n);
        for(int i=0;i<n;i++){
            for(auto &x: favoriteCompanies[i]){
                if(!mp.count(x)){
                    mp[x] = temp++;
                }

                v[i].push_back(mp[x]);
            }
        }

        for(auto &x: v){
            sort(begin(x),end(x));
        }

        vector<int> v1;
        n = v.size();

        for(int i=0;i<n;i++){
            bool flag = true;
            for(int j=0;j<n && flag;j++){
                if(i == j){
                    continue;
                }

                flag = !includes(begin(v[j]),end(v[j]),begin(v[i]),end(v[i]));
            }

            if(flag){
                v1.push_back(i);
            }
        }

        return v1;
    }
};