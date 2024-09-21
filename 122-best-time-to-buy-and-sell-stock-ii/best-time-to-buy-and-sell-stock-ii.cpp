class Solution {
public:
    int maxProfit(vector<int>& p) {
        int r=1;
        int l=0;
        int sum=0;
        
        while(r<p.size())
        {
            if(p[l]<p[r])
            {
                sum += p[r]-p[l];
                
            }
            l=r;
            
            r++;
        }

        return sum;
    }
};