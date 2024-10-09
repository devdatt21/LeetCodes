class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        string str="";
        int cnt=0;

        while(str.size()<b.size())
        {
            str+=a;
            cnt++;
        }

        if(str.find(b)!=string::npos)
        {
            return cnt;
        }

        str+=a;
        cnt++;

        if(str.find(b)!=string::npos)
        {
            return cnt;
        }

        return -1;
    }
};