class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        
        int pref_size = pref.size();
        int cnt = 0;


        for(auto i : words)
        {
            if(pref[0]==i[0])
            {
                if(pref_size==1) 
                {
                    cnt++;
                    continue;
                }

                for(int j=1;j<pref_size;j++)
                {
                    if(i[j]!=pref[j])
                    {
                        break;
                    }

                    if(j+1 == pref_size)
                    {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};