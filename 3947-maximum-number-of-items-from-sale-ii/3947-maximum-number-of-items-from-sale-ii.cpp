
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();

        // Step 1: Find maximum factor
        int mx = 0;
        for (auto &it : items) {
            mx = max(mx, it[0]);
        }

        // Step 2: Frequency of each factor
        vector<int> freq(mx + 1, 0);

        for (auto &it : items) {
            freq[it[0]]++;
        }

        // Step 3: Count items whose factors
        // are divisible by each factor
        vector<int> gain(mx + 1, 0);

        for (int i = 1; i <= mx; i++) {
            for (int j = i; j <= mx; j += i) {
                gain[i] += freq[j];
            }

            // Exclude the item itself
            gain[i]--;
        }

        // Step 4: Sort by price
        sort(items.begin(), items.end(),
             [](const vector<int>& a,
                const vector<int>& b) {
                 return a[1] < b[1];
             });

        int minPrice = items[0][1];
        int ans = 0;

        // Step 5: Buy double-value copies
        for (auto &it : items) {

            int factor = it[0];
            int price = it[1];

            // Not beneficial compared to cheapest item
            if (price >= 2 * minPrice) {
                break;
            }

            int count = gain[factor];

            if (count == 0) continue;

            // Each such purchase costs price
            // and gives 2 total items
            int take = min(count, budget / price);

            ans += 2 * take;
            budget -= take * price;
        }

        // Step 6: Spend remaining budget
        // on the cheapest item
        ans += budget / minPrice;

        return ans;
    }
};
