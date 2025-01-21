class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,int> mp_row;
        unordered_map<int,int> mp_col;
        unordered_map<int, pair<int,int>> mp_mat_value;

        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                mp_mat_value[mat[i][j]] = {i,j};
            }
        }


        for(int i=0;i<arr.size();i++)
        {
            auto val = mp_mat_value[arr[i]];
           
                mp_row[val.first]++;
                mp_col[val.second]++;

                int cnt_row = mp_row[val.first];
                if(cnt_row==mat[0].size())
                {
                    return i;
                }

                int cnt_col = mp_col[val.second];
                if(cnt_col==mat.size())
                {
                    return i;
                }
            

        }

        return 0;


    }
};