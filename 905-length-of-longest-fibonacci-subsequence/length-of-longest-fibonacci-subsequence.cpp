class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        
        unordered_set<int> st;
        st.insert(arr.begin(),arr.end());
        int res=0;

        for (int i=0;i<arr.size();i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                int nxt=arr[i]+arr[j];
                int len=2;
                int prev=arr[i];
                int curr=arr[j];
                while(st.count(nxt)>0)
                {
                    prev=curr;
                    curr=nxt;
                    nxt=prev+curr;
                    len++;
                    res = max(len,res);
                }
            }
        }


        return res;
    }
};