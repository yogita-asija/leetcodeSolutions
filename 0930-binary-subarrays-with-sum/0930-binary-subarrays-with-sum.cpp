class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        unordered_map<int, int> mp;
        
        // Prefix sum 0 exists once before the array starts
        mp[0] = 1;
        
        int prefix = 0;
        int ans = 0;
        
        for (int x : nums) {
            
            prefix += x;
            
            int required = prefix - goal;
            
            if (mp.find(required) != mp.end()) {
                ans += mp[required];
            }
            
            mp[prefix]++;
        }
        
        return ans;
    }
};