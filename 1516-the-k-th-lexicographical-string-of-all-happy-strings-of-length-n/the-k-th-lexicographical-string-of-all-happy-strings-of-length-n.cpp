class Solution {
public:

    void backtrack(int n, string &curr, vector<string> &ans)
    {
        if(curr.size()==n)
        {
            ans.push_back(curr);
            return;
        }

        for(char i='a';i<='c';i++)
        {
            if(!curr.empty() && curr.back()==i)
            {
                continue;
            }

            curr.push_back(i);

            backtrack(n, curr, ans);

            curr.pop_back();
        }
    }


    string getHappyString(int n, int k) {
        string curr="";

        vector<string> ans;

        backtrack(n, curr, ans);

        if(k>ans.size())
            return "";
            
        return ans[k-1];    
    }
};