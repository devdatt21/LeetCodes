class Solution {
public:
    vector<int> lexicalOrder_one(int n) {
        
        vector<int> vec;

        for(int i=1;i<=n;i++)
        {
            vec.push_back(i);
        }

        sort(vec.begin(), vec.end(), [](int a, int b){
            return to_string(a) < to_string(b);
        });

        return vec;
    }

    vector<int> lexicalOrder(int n) {
        
        vector<int> vec(n);
        int num=1;

        for(int ind=0;ind<n;ind++)
        {
            vec[ind] = num;

            if(num*10 > n)
            {
                if(num==n)
                {
                    num = num/10;
                }
                num++;

                while(num%10==0)
                {
                    num = num/10;
                }
            }
            else
            {
                num = num*10;
            }
        }


        return vec;
    }

};