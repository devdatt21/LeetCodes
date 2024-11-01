class Solution {
public:
    string makeFancyString(string s) {
        
        
        string str(1, s[0]);

        int cnt=1;

        for(int i=1;i<s.size();i++)
        {
            char c=s[i];
            if(c==s[i-1])
            {
                cnt++;
                if(cnt>2)
                {
                    continue;
                }
            }
            else
            {
                cnt=1;
            }

            str += s[i];
        }

        return str;
    }
};