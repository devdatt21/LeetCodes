class Solution {
public:
    long long coloredCells(long long n) {
        // n=1 : 1
        // n=2 : 5 
        // n=3 : 13 5 + 4 + (4*cnt:1)
        // n=4 : 25 13 + 4 + (4*cnt:2)
        // n=5 : 41
// 5 = my m
        // long long cnt = 

        return n * (n-1) * 2 + 1LL;
    }
};