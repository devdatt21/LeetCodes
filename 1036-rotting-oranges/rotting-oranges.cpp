class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size()));
        queue<pair<pair<int,int>, int>> q;
        int time=0;
        int fresh_cnt=0;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({{i,j},time});
                }

                if(grid[i][j]==1) fresh_cnt++;

                vis[i][j]=grid[i][j];
            }
        }

        int deltaRow[] = {-1, 0, 1, 0};
        int deltaCol[] = {0, -1, 0, 1};
        int mx_time=0;
        int cnt=0;

        while(!q.empty())
        {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int t = q.front().second;
            q.pop();
            mx_time = max(mx_time,t);
            

            t++;
            for(int i=0;i<4;i++)
            {
                int drow = row + deltaRow[i];
                int dcol = col + deltaCol[i];

                if(drow>-1 && drow<grid.size() && dcol>-1 && dcol<grid[0].size() && vis[drow][dcol]==1)
                {
                    vis[drow][dcol]=2;
                    q.push({{drow,dcol},t});
                    cout << drow << " " << dcol << " time : " << t <<endl;

                    cnt++;

                }
            }
        }

        if(cnt==fresh_cnt) return mx_time;
        return -1;

    }
};