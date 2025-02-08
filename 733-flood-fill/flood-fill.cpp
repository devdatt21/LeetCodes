class Solution {
private:
    void dfs(vector<vector<int>> &ans_image, vector<vector<int>> &image, 
             int row, int col, int cur_color, int nxt_color)
    {
        if(ans_image[row][col]==nxt_color) return;
        ans_image[row][col]=nxt_color;

        int delRow[] = {-1,0,1,0};
        int delCol[] = {0,1,0,-1}; 

        for(int i=0;i<4;i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];

            if(nrow>-1 && nrow<image.size() && ncol>-1 && ncol<image[0].size() &&
                ans_image[nrow][ncol]==cur_color)
            {
                dfs(ans_image, image, nrow, ncol, cur_color, nxt_color);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans_image = image;

        dfs(ans_image, image, sr, sc, image[sr][sc], color);

        return ans_image;

    }
};