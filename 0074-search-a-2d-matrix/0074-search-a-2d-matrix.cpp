class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
	    int	col = matrix[0].size();
        int row2 = 0, col2 = col - 1;
			
        while (row2 < row && col2 > -1) {
            int a = matrix[row2][col2];
            
            if (a == target) 
                return true;
            
            if (target > a) 
                row2++;
            
            else
                col2--;
        }
        
        return false;
    }
};