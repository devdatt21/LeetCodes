class Solution {
public:
    int maximumSwap(int num) {
        string strNum=to_string(num);

        int size=strNum.size();
        vector<int> vec(10, -1);

        for(int i=0;i<size;i++)
        {
            vec[strNum[i]-'0']=i;
        }

        for(int i=0;i<size;i++)
        {
            for(int j=9;j>(strNum[i]-'0');j--)
            {
                if(vec[j]>i)
                {
                    swap(strNum[i], strNum[vec[j]]);
                    return stoi(strNum);
                }
            }
        }

        return num;
    }
};