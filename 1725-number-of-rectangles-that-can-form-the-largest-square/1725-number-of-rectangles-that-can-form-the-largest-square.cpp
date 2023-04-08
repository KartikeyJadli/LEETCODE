class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        unordered_map<int,int>mp;
        int n = rectangles.size();
        for(int i=0;i<n;i++){
            if(rectangles[i][0] < rectangles[i][1]){
                mp[rectangles[i][0]]++;
            }
            
            else{
                mp[rectangles[i][1]]++;
            }
        }

        int m = INT_MIN,count = 0;
        for(auto i: mp){
            if(i.first > m){
                m = i.first;
                count = i.second;
            }
        }

        return count;
    }
};