class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();

        map<int,priority_queue<int,vector<int>,greater<int>>> mp;

        for(int i=0;i<n;i++){
            int temp = nums[i] - 1;

            if(mp.find(temp) == mp.end()){
                mp[nums[i]].push(1);
            }

            else{
                if(mp.find(temp) != mp.end()){
                    int top = mp[temp].top();
                    mp[temp].pop();

                    if(mp[temp].size() == 0){
                        mp.erase(temp);
                    }

                    mp[nums[i]].push(top+1);
                }
            }
        }

        for(auto x: mp){
            auto it = x.second;

            while(!it.empty()){
                if(it.top() < 3){
                    return false;
                }

                it.pop();
            }
        }

        return true;
    }
};