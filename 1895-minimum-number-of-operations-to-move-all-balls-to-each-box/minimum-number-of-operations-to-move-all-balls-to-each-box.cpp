class Solution {
public:
    vector<int> minOperations(string boxes) {
        
        vector<int> vec;

        for(int i=0;i<boxes.size();i++)
        {
            int total_val=0;
            for(int j=0;j<boxes.size();j++)
            {
                if(boxes[j]=='1')
                {
                    int val = abs(j-i);
                    total_val+=val;
                }
            }
            vec.push_back(total_val);
        }

        return vec;
    }
};