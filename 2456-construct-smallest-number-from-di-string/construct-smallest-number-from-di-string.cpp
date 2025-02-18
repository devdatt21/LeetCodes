class Solution {
public:
    string smallestNumber(string pattern) {
        
        string str=pattern;
        stack<int> st;
        int cnt=0;

        for(int i=0;i<pattern.size();i++)
        {
            if(pattern[i]=='I')
            {
                cnt++;

                str[i]=cnt+'0';
                while(!st.empty())
                {
                    int j=st.top();
                    st.pop();
                    cnt++;
                    str[j]=cnt+'0';
                }
            }
            else
            {
                st.push(i);
            }
        }

        while(!st.empty())
        {
            int j=st.top();
            st.pop();
            cnt++;
            str[j]=cnt+'0';
        }

        if(pattern[pattern.size()-1]=='I')
        {
            cnt++;
            str.push_back(cnt+'0');
        }
        else
        {
            char c = str[str.size()-1];
            int i=pattern.size()-1;
            while( i>-1 && pattern[i]!='I')
            {
                str[i]++;
                i--;
            }
            str.push_back(c);


        }

        return str;
    }
};