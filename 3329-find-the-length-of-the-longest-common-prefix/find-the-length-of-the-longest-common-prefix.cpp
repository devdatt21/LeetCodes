class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        unordered_set<int> st;

        for(int i=0;i<arr1.size();i++)
        {
            int x=arr1[i];
            while(x!=0)
            {
                st.insert(x);
                x=x/10;
                
            }
        }
        int ans=0;
        for(int i=0;i<arr2.size();i++)
        {
            int x=arr2[i];
            while(x!=0)
            {
                // st.insert(x);
                if(st.count(x)==1)
                {
                    ans = max(x,ans);
                }
                x=x/10;
                
            }
        }
        
        cout << ans;
        int cnt=0;
        while(ans!=0)
        {
            cnt++;
            ans=ans/10;
        }

        return cnt;
    }
};