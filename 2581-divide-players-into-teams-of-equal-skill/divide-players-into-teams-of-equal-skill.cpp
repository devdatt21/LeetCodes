class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        
        //team size = 2
        
        //number of teams = skill.size()/2;

        //1 1 1 2 2 2 3 3 3 3 4 4 5 9

        sort(skill.begin(),skill.end());
        int sum=skill[0] + skill[skill.size()-1];

        long long ans=0;

        for(int i=0;i<skill.size()/2;i++)
        {
            if((skill[i]+skill[skill.size()-i-1]) != sum ) return -1;

            ans += (skill[i]*skill[skill.size()-i-1]);

        }

        return ans;

    }
};