class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<int> preVec(nums.size());

        int maxEle=INT_MIN;
        for(int i=nums.size()-1;i>=0;i--)
        {
            if(maxEle<nums[i])
            {
                maxEle=nums[i];
            }
            preVec[i]=maxEle;

        }

        int l=0;
        int r=1;
        int winSize=0;
        while(r<nums.size())
        {
            if(nums[l]<=nums[r])
            {
                winSize=max(r-l, winSize);
            }

            if(preVec[r]>=nums[l])
            {
                r++;
            }
            else
            {
                l++;
            }
            

        }

        return winSize;

    }
};