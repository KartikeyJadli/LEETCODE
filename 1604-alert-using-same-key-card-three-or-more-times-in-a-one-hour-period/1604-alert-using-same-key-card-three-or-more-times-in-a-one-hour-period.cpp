class Solution {
    public:
    int toInt(string t){
        int hr = stoi(t.substr(0,2));
        int min = stoi(t.substr(3));
        return hr * 60 + min;
    }

    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
        vector<string> v;
        unordered_map<string,vector<int>> time;
        for(int i=0;i<keyName.size();i++){
            time[keyName[i]].push_back(toInt(keyTime[i]));
        }

        for(auto it=time.begin();it!=time.end();it++){
            sort(it->second.begin(),it->second.end());
            for(int i=0;i<(int)it->second.size()-2;i++){
                if(it->second[i+2] - it->second[i] <= 60){
                    v.push_back(it->first);
                    break;
                }
            }
        }

        sort(v.begin(),v.end());
        return v;
    }
};