class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long result = 0;
        unordered_map<int, int> mp;
        int bits = 0;
        mp[0] = 1;
        for(char ch: word){
            int idx = (ch - 'a');
            bits = bits ^ (1 << idx);
			
            if(mp.find(bits) != mp.end()){
                result += mp[bits];
            }
		
            for(int i=0;i<10;i++){
                int bits2 = bits ^ (1 << i);
                if (mp.find(bits2) != mp.end()) {
                    result += mp[bits2];
                }
            }
            
            mp[bits]++;
        }
        
        return result;
    }
};