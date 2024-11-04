class Solution {
public:
    string compressedString(string word) {

        string comp = ""; // Initialize the compressed string
        int size = word.size();
        int i = 0; // Index to iterate through the word
        
        while (i < size) {
            char c = word[i]; // Get the current character
            int count = 0; // Initialize count of consecutive characters
            
            // Count the maximum length prefix of the same character
            while (i < size && word[i] == c && count < 9) {
                count++;
                i++;
            }
            
            // Append the count followed by the character to comp
            comp += to_string(count) + c;
        }
        
        return comp; // Return the compressed string
    
    }
};