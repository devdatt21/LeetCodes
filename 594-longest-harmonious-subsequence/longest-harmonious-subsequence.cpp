class Solution {
public:
    int findLHS(vector<int>& nums) {
        int mx=0;
        unordered_map<int,int> ump;

        for(int i=0;i<nums.size();i++)
        {
            ump[nums[i]]++;
        }

        for(auto& i : ump)
        {
            if(ump.count((i.first)+1))
            {
                mx = max(mx, ump[(i.first)] + ump[(i.first)+1]);
            } 
        }

        return mx;
    }
};