class Solution {
public:
    bool check(vector<int>& nums) {
        if(nums[0] < nums[nums.size()-1])
        {
            for(int i=1;i<nums.size();i++)
            {
                if(nums[i-1]>nums[i])
                {
                    return false;
                }
            }   

            return true;
        }
        else
        {
            for(int i=1;i<nums.size();i++)
            {
                if(nums[i-1]>nums[i])
                {
                    for(int j=i+1;j<nums.size();j++)
                    {
                        if(j<nums.size())
                        {
                            if(nums[j-1]>nums[j])
                            {
                                return false;
                            }
                        }
                        
                    }
                }
            }   

            return true;
        }
    }
};