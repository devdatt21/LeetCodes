class Solution {
public:
    long long coloredCells(int n) {
        // n=1 : 1
        // n=2 : 5 
        // n=3 : 13 5 + 4 + (4*cnt:1)
        // n=4 : 25 13 + 4 + (4*cnt:2)
        // n=5 : 41

        // long long cnt = 

        if(n==1) return 1;
        if(n==2) return 5;

        long long cnt = 1;
        vector<long long> vec(n+1,0);
        vec[1]=1;
        vec[2]=5;

        for(int i=3;i<=n;i++)
        {
            vec[i]=vec[i-1] + 4 + (4*cnt++);
        }

        return vec[n];
    }
};