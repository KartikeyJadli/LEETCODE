class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_set<string> ss(supplies.begin(),supplies.end());
        bool flag = true;
        int n = recipes.size();
        vector<int> v(n,false);
        vector<string> str;
        while(flag){
            flag = false;
            for(int i=0;i<n;i++){
                if(v[i]){
                    continue;
                }

                bool temp = true;
                for(string &s:ingredients[i]){
                    if(ss.find(s) == ss.end()){
                        temp = false;
                        break;
                    }
                }

                if(temp){
                    flag = true;
                    ss.insert(recipes[i]);
                    v[i]=true;
                    str.push_back(recipes[i]);
                }
            }
        }

        return str;
    }
};