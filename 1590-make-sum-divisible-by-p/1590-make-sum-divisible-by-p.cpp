class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {

        long long total = 0;

        for (int x : nums) {
            total += x;
        }

        int rem = total % p;

        // Already divisible
        if (rem == 0)
            return 0;

        unordered_map<int, int> mp;

        // remainder 0 before the array starts
        mp[0] = -1;

        long long prefix = 0;
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) {

            prefix += nums[i];

            int curr = prefix % p;

            int needed = (curr - rem + p) % p;

            if (mp.find(needed) != mp.end()) {

                int len = i - mp[needed];

                ans = min(ans, len);
            }

            // Store latest index
            mp[curr] = i;
        }

        // Cannot remove the entire array
        if (ans == nums.size())
            return -1;

        return ans;
    }
};