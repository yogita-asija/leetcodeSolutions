class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        
        unordered_map<int, int> mp;
        
        mp[0] = 1;
        
        int prefix = 0;
        int ans = 0;
        
        for (int x : nums) {
            
            // Odd -> 1
            // Even -> 0
            prefix += (x % 2);
            
            // Need previous prefix = current prefix - k
            ans += mp[prefix - k];
            
            // Store current prefix
            mp[prefix]++;
        }
        
        return ans;
    }
};