class Solution {
public:
     int smallestChair(vector<vector<int>>& times, int targetFriend) {
        // Append the index (friend number) to each time interval
        for (int i = 0; i < times.size(); i++) {
            times[i].push_back(i);
        }

        // Sort times by arrival time, and in case of tie, by departure time
        sort(times.begin(), times.end(), [](vector<int>& a, vector<int>& b) {
            return a[0] < b[0];
        });

        // Min-heap to store available chairs
        priority_queue<int, vector<int>, greater<int>> availableChairs;

        // Min-heap to track when a chair is freed. Stores {departure time, chair number}.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupiedChairs;

        // Initially, all chairs are free, so push all chair numbers to availableChairs
        for (int i = 0; i < times.size(); ++i) {
            availableChairs.push(i);
        }

        // Iterate over each friend
        for (auto& friendTime : times) {
            int arrival = friendTime[0];
            int departure = friendTime[1];
            int friendIdx = friendTime[2];

            // Free up any chairs that are now available by the current arrival time
            while (!occupiedChairs.empty() && occupiedChairs.top().first <= arrival) {
                availableChairs.push(occupiedChairs.top().second);
                occupiedChairs.pop();
            }

            // Assign the smallest available chair
            int assignedChair = availableChairs.top();
            availableChairs.pop();

            // Record when the chair will be freed
            occupiedChairs.push({departure, assignedChair});

            // If this is the target friend, return the chair number
            if (friendIdx == targetFriend) {
                return assignedChair;
            }
        }

        // In case we don't find the target friend (which shouldn't happen)
        return -1;
    }
};