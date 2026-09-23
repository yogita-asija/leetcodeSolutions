class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        unordered_map<int, int> mp;

        // remainder 0 exists before the array starts
        mp[0] = -1;

        long long prefixSum = 0;

        for (int i = 0; i < nums.size(); i++) {

            prefixSum += nums[i];

            int rem = prefixSum % k;

            // Remainder already seen
            if (mp.find(rem) != mp.end()) {

                int prevIndex = mp[rem];

                // Subarray length must be at least 2
                if (i - prevIndex >= 2) {
                    return true;
                }

            }
            else {
                // Store only the first occurrence
                mp[rem] = i;
            }
        }

        return false;
    }
};