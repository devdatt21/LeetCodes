class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        unordered_map<int,int> mp;
        int cnt=0;
        int preSum=0;
        mp[0]=1;

        for(auto i : nums)
        {
            preSum+=i;

            int mod=preSum%k;

            if(mod<0)
            {
                mod+=k;
            }

            if(mp.find(mod)!=mp.end())
            {
                cnt+=mp[mod];
                mp[mod]++;
            }
            else
            {
                mp[mod]=1;
            }
        }

        
        return cnt;
    }
};