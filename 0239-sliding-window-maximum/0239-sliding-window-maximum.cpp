class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq; // Stores indices
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {

            // 1. Remove indices outside the window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // 2. Maintain decreasing order of values
            while (!dq.empty() &&
                   nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // 3. Insert current index
            dq.push_back(i);

            // 4. Record maximum once window is complete
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }

        return ans;
    }
};