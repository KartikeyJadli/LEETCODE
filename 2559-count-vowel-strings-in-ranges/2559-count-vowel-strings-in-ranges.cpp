class Solution {
public:
    bool validate(char &x){
        if(x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u'){
            return true;
        }

        return false;
    }

    vector<int> vowelStrings(vector<string>& words,vector<vector<int>>& queries) {
        int n = words.size();
        vector<int> v(n,0);

        for(int i=0;i<n;i++){
            string str = words[i];
            if(validate(str[0]) == true && validate(str[str.length()-1]) == true){
                v[i]++;
            }
        }  

        for(int i=1;i<v.size();i++){
            v[i] += v[i-1];
        }      

        vector<int> v1;
        n = queries.size();

        for(int i=0;i<n;i++){
            int temp = queries[i][0];
            int temp2 = queries[i][1];

            if(temp == 0){
                v1.push_back(v[temp2]);
            }

            else{
                v1.push_back(v[temp2] - v[temp-1]);
            }
        }

        return v1;
    }
};