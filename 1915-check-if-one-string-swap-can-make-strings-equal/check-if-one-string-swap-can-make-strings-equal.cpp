class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return 1;

        char a;
        char b;
        int cnt=0;

        int got=0;
        for(int i=0;i<s1.size();i++)
        {
            if(s1[i]!=s2[i] && cnt<3)
            {   
                cnt++;
                if(cnt==2)
                {
                    if(a==s2[i] && b==s1[i])
                    {
                        got=1;
                    }
                }
                a=s1[i];
                b=s2[i];
                
            }
            
        }

        if(cnt==2 && got) return 1;
        return 0;


    }
};