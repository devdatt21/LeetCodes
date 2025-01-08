class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        
        int cnt=0;
        if(words.size()<2)
        {
            return 0;
        }
        
        for(int i=0;i<words.size();i++)
        {
            string word1 = words[i];

            for(int j=i+1;j<words.size();j++)
            {
                string word2 = words[j];

                if(word1.size()<=word2.size())
                {
                    int pre=0;
                    int pos=0;

                    //prefix
                    for(int k=0;k<word1.size();k++)
                    {
                        if(word1[k]!=word2[k])
                        {
                            break;
                        }
                        if(k+1 == word1.size())
                        {
                            pre=1;
                        }
                    }

                    //postfix
                    int size2 = word2.size();

                    for(int k=word1.size()-1;k>=0;k--)
                    {
                        if(word1[k]!=word2[--size2])
                        {
                            break;
                        }
                        if(k == 0)
                        {
                            pos=1;
                        }
                    }

                    if(pos && pre)
                    {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
        
    }
};