class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> vec((grid.size()*grid.size())+1,0);


        for(auto i : grid)
        {
            for(auto j : i)
            {
                vec[j]++;
            }
        }

        int x=0,y=0;
        for(int i=0;i<grid.size()*grid.size()+1;i++)
        {
            if(vec[i]==2)
            {
                x=i;
            }

            if(i!=0 && vec[i]==0)
            {
                y=i;
            }
        }

        return {x,y};
    }
};