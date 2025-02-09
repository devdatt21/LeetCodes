class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        long long cnt=0;
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++)
        {
            int key = nums[i]-i;
            cnt+=mp[key];
            mp[key]++;
        }

        long long x = (nums.size()*(nums.size()-1))/2;
        return x-cnt;
    }
};