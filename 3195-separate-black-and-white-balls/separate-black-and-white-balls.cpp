class Solution {
public:
    long long minimumSteps(string s) {
        
        long long cnt=0;

        int l=s.size()-1;
        int r=s.size()-1;;

        while(l>=0 && r>=0)
        {
            if(s[l]=='1' && s[r]=='0' && l<r)
            {
                swap(s[l],s[r]);
                cnt += r-l;
                r--;
                l--;
            }
            else if(s[r]!='0')
            {
                r--;
            }
            else
            {
                l--;
            }


        }

        return cnt;
    }
};