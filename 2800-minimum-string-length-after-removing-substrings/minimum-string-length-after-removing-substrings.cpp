class Solution {
public:
    int minLength(string s) {
        stack<string> st;
        // string word="";
        int cnt=0;

        for(int i=0;i<s.size();i++)
        {
            if(!st.empty())
            {
                string c=st.top();

                if((c+s[i])=="AB" || (c+s[i])=="CD")
                {
                    st.pop();
                    // word.pop_back();
                    cnt--;

                    continue;
                }
                
            }

            // word.push_back(s[i]);
            cnt++;
            st.push(string(1,s[i]));
            

        }

        // cout << word << endl;
        return cnt;
    }
};