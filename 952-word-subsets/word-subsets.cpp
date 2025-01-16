class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<int> maxFreq(26, 0);
        for (string& word : words2) {
            vector<int> freq(26, 0);
            for (char ch : word) {
                freq[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                maxFreq[i] = max(maxFreq[i], freq[i]);
            }
        }
        
        vector<string> result;

        for (string& word : words1) {
            vector<int> freq(26, 0);
            for (char ch : word) {
                freq[ch - 'a']++;
            }
            
            // Verify if word meets the maxFreq requirements
            bool isValid = true;
            for (int i = 0; i < 26; i++) {
                if (freq[i] < maxFreq[i]) {
                    isValid = false;
                    break;
                }
            }
            
            if (isValid) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};