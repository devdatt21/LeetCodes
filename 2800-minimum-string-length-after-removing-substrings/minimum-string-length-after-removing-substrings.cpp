class Solution {
public:
    int minLength(string s) {
        stack<char> st;

        for(int i=0;i<s.size();i++)
        {
            if(!st.empty())
            {
                char c=st.top();

                if(c=='A' && s[i]=='B' || c=='C' && s[i]=='D')
                {
                    st.pop();

                    continue;
                }
                
            }
            st.push(s[i]);
            

        }

        // cout << word << endl;
        return st.size();
    }
};