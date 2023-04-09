class Solution {
public:
    int binarysearch(vector<int> &grid){
        int low = 0,high = grid.size() - 1;
        while(low <= high){
            int mid = low + (high - low)/2;

            if(grid[mid] >= 0){
                low = mid + 1;
            }

            else{
                high = mid - 1;
            }
        }

        return grid.size() - high - 1;
    }

    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        for(auto x: grid){
            // cout << upper_bound(x.begin(),x.end(),-1) - x.begin() << endl;
            count += binarysearch(x);
        }

        return count;
    }
};