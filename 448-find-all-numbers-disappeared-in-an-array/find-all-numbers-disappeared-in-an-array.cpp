class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        // auto mx = max_element(nums.begin(), nums.end());

        vector<int> vec(nums.size()+1,0);

        for(int i=0;i<nums.size();i++)
        {
            vec[nums[i]]=1;
        }

        vector<int> ans;

        for(int i=1;i<vec.size();i++)
        {
            if(vec[i]==0)
            {
                ans.push_back(i);
            }
        }

        return ans;
    }
};