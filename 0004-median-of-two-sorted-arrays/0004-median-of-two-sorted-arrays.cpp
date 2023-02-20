class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        if(m > n){
            return findMedianSortedArrays(nums2,nums1);
        }

        int low = 0,high = m;

        while(low <= high){
            int part1 = (low + high)/2;
            int part2 = (m + n + 1)/2 - part1;

            int l1 = INT_MIN;
            int l2 = INT_MIN;
            int r1 = INT_MAX;
            int r2 = INT_MAX;

            if(part1 > 0){
                l1 = nums1[part1 - 1];
            }

            if(part2 > 0){
                l2 = nums2[part2 - 1];
            }

            if(part1 < m){
                r1 = nums1[part1];
            }

            if(part2 < n){
                r2 = nums2[part2];
            }

            if(l1 <= r2 && l2 <= r1){
                if((m + n) % 2 == 0){
                    double med = (max(l1,l2) + min(r1,r2))/2.0;
                    return med;
                }

                else{
                    return (double)max(l1,l2);
                }
            }

            else if(l1 > r2){
                high = part1 - 1;
            }

            else{
                low = part1 + 1;
            }
        }

        return 0.0;
    }
};