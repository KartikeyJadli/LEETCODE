class Solution {
public:
    string predictPartyVictory(string s){
        set<int> r,d;
            int n=s.length();
            for(int i=0;i<n;i++)
            {
                if(s[i]=='R')r.insert(i);
                else d.insert(i);
            }
        while(r.size()>0&&d.size()>0){   
            for(int i=0;i<n;i++)
            {
                if(s[i]=='R')
                {
                    if(d.empty())
                    {
                        return "Radiant";
                    }
                    else
                    {
                auto it=d.lower_bound(i);
                        if(it==d.end())
                        {
                            s[*d.begin()]='~';
                            d.erase(d.begin());
                        }
                        else
                        {
                            s[*it]='~';
                            d.erase(it);
                        }
                        
                        if(d.empty())
                        {
                            return "Radiant";
                        }
                    }
                }
                else if(s[i]=='D')
                {
                    if(r.empty())
                    {
                        return "Dire";
                    }
                    else
                    {
                        auto it=r.lower_bound(i);
                        if(it==r.end()){
                        s[*r.begin()]='~';
                        r.erase(r.begin());
                        }
                        else
                        {
                            s[*it]='~';
                            r.erase(it);
                        }
                        if(r.empty())
                    {
                        return "Dire";
                    }

                        
                    }
                }
            }
        }

            if(d.empty())return "Radiant";
        
            else return "Dire";
    }
};