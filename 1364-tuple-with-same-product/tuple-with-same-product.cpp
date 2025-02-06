class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                int mul = nums[i]*nums[j];
                mp[mul]++;
            }
        }   

        for(auto i : mp)
        {
            if(i.second>1)
            {
                int num = (i.second * (i.second-1))/2;
                ans += num*8;
            }
        }
        return ans;
    }
};