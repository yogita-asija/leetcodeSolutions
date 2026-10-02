class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& nums) {

        int n = nums.size();

        vector<int> ans(n, -1);

        stack<int> s1;  // waiting for 1st greater
        stack<int> s2;  // waiting for 2nd greater

        for(int i = 0; i < n; i++) {

            // Step 1: Find second greater
            while(!s2.empty() && nums[s2.top()] < nums[i]) {

                ans[s2.top()] = nums[i];
                s2.pop();
            }

            // Step 2: Find first greater
            vector<int> temp;

            while(!s1.empty() && nums[s1.top()] < nums[i]) {

                temp.push_back(s1.top());
                s1.pop();
            }

            // Move them to second stack
            for(int j = temp.size() - 1; j >= 0; j--) {
                s2.push(temp[j]);
            }

            // Current element waits for first greater
            s1.push(i);
        }

        return ans;
    }
};