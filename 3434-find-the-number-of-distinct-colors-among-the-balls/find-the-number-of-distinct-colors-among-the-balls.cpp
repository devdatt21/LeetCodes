class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballMpp;   
        unordered_map<int, int> colorMpp;

        vector<int> ans;
        for(auto &it:queries){
            int ball = it[0];
            int color = it[1];

            if(ballMpp.count(ball) > 0){
                colorMpp[ballMpp[ball]]--;
                if(colorMpp[ballMpp[ball]] == 0){
                    colorMpp.erase(ballMpp[ball]);
                }
            }

            ballMpp[ball] = color;
            colorMpp[color]++;

            ans.push_back(colorMpp.size());
        }
        return ans;   
    }
};