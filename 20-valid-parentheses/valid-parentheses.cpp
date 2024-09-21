class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                st.push(')');
            }
            else if(s[i]=='{')
            {
                st.push('}');
            }
            else if(s[i]=='[')
            {
                st.push(']');
            }
            else
            {
                if(!st.empty() && st.top()==s[i])
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
        }

        if(st.size()==0)
        {
            return true;
        }

        return false;

        return 0;
    }
};