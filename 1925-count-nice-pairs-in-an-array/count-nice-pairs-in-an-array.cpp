class Solution {
public:
    int rev(int num) {
        int reverse = 0;
        while (num > 0) {
            int lastDigit = num % 10;   // Extract last digit
            reverse = reverse * 10 + lastDigit; // Append digit to reverse
            num = num / 10;  // Remove last digit
        }
        return reverse;
    }

    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        int cnt=0;
        int mod=1e9+7;

        for(int i=0;i<nums.size();i++)
        {
            int key = nums[i]-rev(nums[i]);
            cnt = (cnt + mp[key])%mod;
            mp[key]++;
        }

        return cnt;
    }
};