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

        cout << st.size() << endl;

        int n = st.size()/2;

        if (n <= 0) {
            return 0; // or throw an exception for invalid input
        }
        return (n + 1) / 2;

        // return ans;
    }
};