class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {

        // Step 1: Count frequency
        unordered_map<int, int> freq;

        for (int x : nums) {
            freq[x]++;
        }

        // Step 2: Custom sorting
        sort(nums.begin(), nums.end(),
            [&](int a, int b) {

                // Lower frequency first
                if (freq[a] != freq[b]) {
                    return freq[a] < freq[b];
                }

                // Same frequency -> larger number first
                return a > b;
            });

        return nums;
    }
};