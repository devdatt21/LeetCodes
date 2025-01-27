class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prereq, vector<vector<int>>& queries) {
        
        vector<bool> ans;
        unordered_map<int, unordered_set<int>> reachable;

        for(auto pre : prereq)
        {
            reachable[pre[1]].insert(pre[0]);
        }

        for(int i=0;i<numCourses;i++)
        {
            for(int j=0;j<numCourses;j++)
            {
                if(reachable[j].count(i)>0)
                {
                    reachable[j].insert(reachable[i].begin(),reachable[i].end());
                }
            }
        }

        for(auto q : queries)
        {
            ans.push_back(reachable[q[1]].count(q[0])>0);
        }

        return ans;
        
    }
};