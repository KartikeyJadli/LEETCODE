class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long conti = 0,count = 0;
				for(auto x: nums){
					if(x == 0){
						conti++;
					}
								
					else{
						if(conti){
							count += (conti) * 1LL * (conti + 1)/2;
						}

						conti = 0;
					}
				}

				if(conti){
					count += (conti) * 1LL * (conti + 1)/2;
				}

				return count;
    }
};