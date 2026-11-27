
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        int minPrice = INT_MAX;

        for (auto &item : items) {
            minPrice = min(minPrice, item[1]);
        }

        vector<int> dp(budget + 1, -1e9);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            int factor = items[i][0];
            int price = items[i][1];

            int freeCnt = 0;

            // Count free items received
            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % factor == 0) {
                    freeCnt++;
                }
            }

            // 0/1 Knapsack
            for (int j = budget; j >= price; j--) {
                dp[j] = max(
                    dp[j],
                    dp[j - price] + freeCnt + 1
                );
            }
        }

        int ans = 0;

        // Buy cheapest items with remaining budget
        for (int j = 0; j <= budget; j++) {
            if (dp[j] >= 0) {
                ans = max(ans,
                    dp[j] + (budget - j) / minPrice);
            }
        }

        return ans;
    }
};
