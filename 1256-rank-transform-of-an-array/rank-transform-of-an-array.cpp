class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        
        set<int> st;
        unordered_map<int,int> mp;

        for(auto i : arr)
        {
            st.insert(i);
        }

        int rank=0;
        for(auto i : st)
        {
            rank++;
            mp[i]=rank;
        }

        vector<int> vec;

        for(auto i : arr)
        {
            vec.push_back(mp[i]);
        }
        return vec;
    }
};