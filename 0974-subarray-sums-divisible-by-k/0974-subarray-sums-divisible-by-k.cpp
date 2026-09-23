class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        unordered_map<int,int>freq;

        freq[0]=1;
        long long prefixSum=0;
        int ans=0;

        for (int x:nums){
            prefixSum+=x;

            int rem= prefixSum % k;

            if(rem<0){
                rem += k;
            }
            ans += freq[rem];
        freq[rem]++;
           
        }
        return ans;
        
        
    }
};