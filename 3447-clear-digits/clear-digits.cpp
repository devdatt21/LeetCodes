class Solution {
public:
    string clearDigits(string s) {
        string str="";
        int dig_cnt=0;

        for(int i=s.size()-1;i>=0;i--)
        {
            if(isdigit(s[i]))
            {
                dig_cnt++;
            }
            
            

            if(dig_cnt==0)
            {
                str+=s[i];
            }
            if(dig_cnt>0 && isalpha(s[i]))
            {
                dig_cnt--;
            }
        }

        reverse(str.begin(),str.end());

        return str;
    }
};