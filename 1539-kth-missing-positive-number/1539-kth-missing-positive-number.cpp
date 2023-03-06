class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int count = 0;
        
        for(int i=1;i<=10000;i++){
            
            int low = 0;
            int high = arr.size()-1;
            
            while(low <= high){
                
                int mid = low + (high - low)/2;
                
                if(arr[mid]==i)
                    break;
                
                else if(arr[mid]<i)
                    low = mid + 1;
                
                else
                    high = mid - 1;
            }
            
            if(low > high)
                count++;
            
            if(count == k)
                return i;
        }
        
        return -1;
    }
};