class Solution {
public:
    int minLength(string s) {
        stack<string> st;
        string word="";

        for(int i=0;i<s.size();i++)
        {
            if(!st.empty())
            {
                string c=st.top();

                if((c+s[i])=="AB" || (c+s[i])=="CD")
                {
                    st.pop();
                    word.pop_back();
                    continue;
                }
                
            }

            word.push_back(s[i]);
            st.push(string(1,s[i]));
            

        }

        cout << word << endl;
        return word.size();
    }
};