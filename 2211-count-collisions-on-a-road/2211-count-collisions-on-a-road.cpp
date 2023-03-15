class Solution {
public:
	int countCollisions(string s) {
		int res = 0, cnt = 0;
		char prev = s[0];
		for(int i = 1;i<s.length();i++){
			if(prev =='R'){
				if(s[i]=='L') {
					res+=2+cnt;
					prev = 'S';
					cnt = 0;
					continue;
				}

				else if(s[i]=='S'){
					res+=1+cnt;
					prev = 'S';
					cnt = 0;
					continue;
				}

				else{
                    prev = s[i];
                }

                cnt++;
			}

			else if(prev=='S'){
				if(s[i]=='L') res+=1;
				else prev = s[i];
			}

			else{
                prev = s[i];
            }
		}

		return res;
	}
};