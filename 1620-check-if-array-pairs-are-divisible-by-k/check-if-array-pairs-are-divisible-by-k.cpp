class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        
        vector<int> vec(k);

        for(int i=0;i<arr.size();i++)
        {
            int rem = arr[i]%k;

            cout << rem << endl;
            if (rem < 0) {
                rem += k;
            }
            vec[rem]++;

        }

        if(vec[0]%2!=0) return false;

        for(int i=1;i<=k/2;i++)
        {
            if(vec[i]!=vec[k-i]) return false;
        }


        return true;
    }
};