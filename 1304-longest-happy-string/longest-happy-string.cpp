class Solution {
public:
    struct CompareByValue {
        bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
            // Return true if a's value is less than b's value (for max-heap)
            return a.second < b.second;
        }
    };

    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, CompareByValue> pq;
        
        if (a > 0) pq.push({'a', a});
        if (b > 0) pq.push({'b', b});
        if (c > 0) pq.push({'c', c});

        string result = "";

        while (!pq.empty()) {
            // Get the character with the most remaining count
            pair<char, int> top = pq.top();
            pq.pop();

            // If the last two characters are the same as the current top, try using the second most frequent character
            if (result.size() >= 2 && result.back() == top.first && result[result.size() - 2] == top.first) {
                // If the priority queue is empty, break the loop as no valid character is left
                if (pq.empty()) {
                    break;
                }

                pair<char, int> top2 = pq.top();
                pq.pop();
                
                // Use the second most frequent character
                result += top2.first;
                top2.second--;

                // Put top2 back into the queue if there's still more of it left
                if (top2.second > 0) {
                    pq.push(top2);
                }

                // Put the first character back into the queue for later use
                pq.push(top);
            } else {
                // Use the character with the most count
                result += top.first;
                top.second--;

                // Put the character back into the queue if there's still more of it left
                if (top.second > 0) {
                    pq.push(top);
                }
            }
        }

        return result;
    }
};