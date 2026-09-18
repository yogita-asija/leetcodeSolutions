class Solution {
public:
    int jobScheduling(vector<int>& startTime,
                      vector<int>& endTime,
                      vector<int>& profit) {

        int n = startTime.size();

        vector<array<int,3>> jobs;

        for(int i = 0; i < n; i++) {
            jobs.push_back({
                startTime[i],
                endTime[i],
                profit[i]
            });
        }

        // Sort by end time
        sort(jobs.begin(), jobs.end(),
             [](auto &a, auto &b) {
                 return a[1] < b[1];
             });

        vector<int> ends(n);

        for(int i = 0; i < n; i++) {
            ends[i] = jobs[i][1];
        }

        vector<int> dp(n);

        for(int i = 0; i < n; i++) {

            // Option 1: Skip current job
            int skip = (i > 0) ? dp[i - 1] : 0;

            // Find last job with end <= current start
            int index =
                upper_bound(
                    ends.begin(),
                    ends.begin() + i,
                    jobs[i][0]
                ) - ends.begin() - 1;

            // Option 2: Take current job
            int take = jobs[i][2];

            if(index >= 0) {
                take += dp[index];
            }

            dp[i] = max(skip, take);
        }

        return dp[n - 1];
    }
};