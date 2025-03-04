class Solution {
public:
    bool rec( int i ,long long n , long long x , vector<long long>& v)
    {
        if(x == n)
        {
            return true;
        }

        if(i >= 17)
        {
            return false;
        }

        return rec(i+1,n,x,v) || rec(i+1,n,x+v[i],v);
    }


    bool checkPowersOfThree(int n) {
        vector<long long> v(17,0);
        int mod=1e9+7;

        v[0]=1;

        for(int i=1;i<17;i++)
        {
           v[i] = (v[i-1]*3)%mod;
        }

        return rec(0,n,0,v);
    }
};