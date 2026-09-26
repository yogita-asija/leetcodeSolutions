class Solution {
public:

    vector<int> ans;

    void mergeSort(vector<pair<int,int>>& nums, int left, int right) {

        if (left >= right)
            return;

        int mid = left + (right - left) / 2;

        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);

        merge(nums, left, mid, right);
    }

    void merge(vector<pair<int,int>>& nums,
               int left, int mid, int right) {

        vector<pair<int,int>> temp;

        int i = mid;
        int j = right;

        // Merge from right to left
        while (i >= left && j >= mid + 1) {

            if (nums[i].first > nums[j].first) {

                ans[nums[i].second] +=
                    j - mid;

                temp.push_back(nums[i]);
                i--;

            } else {

                temp.push_back(nums[j]);
                j--;
            }
        }

        while (i >= left) {
            temp.push_back(nums[i]);
            i--;
        }

        while (j >= mid + 1) {
            temp.push_back(nums[j]);
            j--;
        }

        // temp is currently descending
        reverse(temp.begin(), temp.end());

        for (int k = 0; k < temp.size(); k++) {
            nums[left + k] = temp[k];
        }
    }

    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();

        ans.assign(n, 0);

        vector<pair<int,int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        mergeSort(arr, 0, n - 1);

        return ans;
    }
};