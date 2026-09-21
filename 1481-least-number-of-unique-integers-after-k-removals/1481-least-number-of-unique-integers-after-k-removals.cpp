class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {

        // Step 1: Count frequency
        unordered_map<int, int> freq;

        for (int x : arr) {
            freq[x]++;
        }

        // Step 2: Store frequencies
        vector<int> frequencies;

        for (auto& [num, count] : freq) {
            frequencies.push_back(count);
        }

        // Step 3: Sort frequencies
        sort(frequencies.begin(), frequencies.end());

        // Initially all numbers are unique
        int unique = frequencies.size();

        // Step 4: Remove least frequent numbers first
        for (int f : frequencies) {

            if (k >= f) {
                k -= f;
                unique--;
            }
            else {
                break;
            }
        }

        return unique;
    }
};