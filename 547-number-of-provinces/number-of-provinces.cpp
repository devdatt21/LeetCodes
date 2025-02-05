class Solution {
public:

    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj_list)
    {
        if(vis[node]==1) return;

        vis[node]=1;
        for(auto i : adj_list[node])
        {
            dfs(i, vis, adj_list);
        }
        
    }
    

    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int size = isConnected.size();

        vector<vector<int>> adj_list(isConnected.size());
        
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                if(isConnected[i][j]==1 && i!=j)
                {
                    adj_list[i].push_back(j);
                }
            }
        }

        vector<int> vis(isConnected.size(),0);
        int cnt=0;

        for(int i=0;i<isConnected.size();i++)
        {
            if(vis[i]==0) cnt++;
            dfs(i, vis, adj_list);
        }

        return cnt;
    }
};