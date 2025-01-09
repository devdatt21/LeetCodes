class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& a, string& b){
            return a.size() < b.size();
        });
        set<string> ans;

        for(int i=0;i<words.size();i++)
        {
            string word1=words[i];

            for(int j=i+1;j<words.size();j++)
            {
                string word2=words[j];

                int size_word2 = words[j].size();
                int size_matched=0;
                
                for(int k=0;k<size_word2;k++)
                {
                    if(word2[k]==word1[0])
                    {
                        // int q=k;
                        for(int l=0;l<word1.size();l++)
                        {
                            if(word2[k+l]!=word1[l])
                            {
                                break;
                            }

                            if(l+1 == word1.size())
                            {
                                ans.insert(word1);
                            }
                        }
                    }
                }
            }
        }

        vector<string> vec;
        for(auto i : ans)
        {
            vec.push_back(i);
        }
        return vec;
    }
};