#define ll long long 

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
            
        long long i=0;
        long long cnt=0;
        
        //1 1 2 4 9
        //0 1 2 3 4
        //3 2 4 9
        //
        
        multiset<ll> mset;
        
        for(auto i : nums)
        {
            mset.insert(i);
        }
        
        while(*(mset.begin())<k)
        {
            
            cnt++;
            long long x;
            long long two = 2;
            
            x = *(mset.begin()) * two;
            mset.erase(mset.begin());  
            
            x += *(mset.begin());
            mset.erase(mset.begin());

            mset.insert(x);
                            
        }
        
        
        
        return cnt;
        
    }
};