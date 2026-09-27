class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {

        unordered_map<int, long long> mp;
        mp[0]=1;

        long long ans=0;
        int prefix=0;

        for (int x:nums){

            if (x % modulo == k)
               prefix++;

               int curr = prefix % modulo;
               
               int needed=(curr - k + modulo)% modulo;

               if (mp.count(needed))
                   ans+= mp[needed];

               mp[curr]++;
        }
        return ans;
        
    }
};