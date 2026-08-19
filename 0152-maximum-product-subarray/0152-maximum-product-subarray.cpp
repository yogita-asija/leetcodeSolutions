class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProduct = nums[0];
        int minProduct = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];

            int prevMax = maxProduct;
            int prevMin = minProduct;

            maxProduct = max({x, x * prevMax, x * prevMin});
            minProduct = min({x, x * prevMax, x * prevMin});

            ans = max(ans, maxProduct);
        }

        return ans;
    }
};