class Solution {
public:
    int maxArea(vector<int>& h) {
        int left=0;
        int right=h.size()-1;
        int maxCap=0;

        while(left<right)
        {
            int smalleBar = min(h[left], h[right]);
            int cap = (right - left) * smalleBar;

            maxCap = max(cap, maxCap);

            if(h[left]<h[right])
            {
                left++;
            }
            else
            {
                right--;
            }

        }

        return maxCap;
    }
};