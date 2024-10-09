class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        st.push(s[0]);

        for(int i=1;i<s.size();i++)
        {

            if(!st.empty() && st.top()=='[' && s[i]==']')
            {
                st.pop();
                continue;
            }

            st.push(s[i]);
        }

        return ((st.size()/2) + 1) / 2;

    }
};