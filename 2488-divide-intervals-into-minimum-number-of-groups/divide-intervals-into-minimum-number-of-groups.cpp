class Solution {
public:
    int minGroups(vector<vector<int>>& in) {
        //here we just have to count maximum overlapping intervals

        vector<int> vec1;
        vector<int> vec2;

        for(auto i : in)
        {
            vec1.push_back(i[0]);
            vec2.push_back(i[1]);
        }

        sort(vec1.begin(),vec1.end());
        sort(vec2.begin(),vec2.end());

        int l1=0;
        int l2=0;
        int grps=0;
        int maxGrps=0;

        while(l1<in.size())
        {
            if(vec1[l1]<=vec2[l2])
            {
                l1++;
                grps++;
            }
            else
            {
                l2++;
                grps--;
            }

            maxGrps=max(maxGrps, grps);
        }

        return maxGrps;

    }
};