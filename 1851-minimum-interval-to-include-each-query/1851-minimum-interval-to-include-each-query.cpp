class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals,
                            vector<int>& queries) {

        // Step 1: Sort intervals by starting point
        sort(intervals.begin(), intervals.end());

        // Step 2: Store queries with their original indices
        vector<pair<int, int>> qs;

        for(int i = 0; i < queries.size(); i++) {
            qs.push_back({queries[i], i});
        }

        sort(qs.begin(), qs.end());

        // Min-heap:
        // {interval size, interval end}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        vector<int> ans(queries.size(), -1);

        int i = 0;

        // Step 3: Process sorted queries
        for(auto [q, index] : qs) {

            // Add all intervals whose start <= query
            while(i < intervals.size() &&
                  intervals[i][0] <= q) {

                int start = intervals[i][0];
                int end = intervals[i][1];

                int size = end - start + 1;

                pq.push({size, end});

                i++;
            }

            // Remove intervals that don't contain q
            while(!pq.empty() &&
                  pq.top().second < q) {

                pq.pop();
            }

            // Smallest valid interval
            if(!pq.empty()) {
                ans[index] = pq.top().first;
            }
        }

        return ans;
    }
};