class Solution {
public:
    string frequencySort(string s) {

        // Step 1: Count frequency
        unordered_map<char, int> freq;

        for (char ch : s) {
            freq[ch]++;
        }

        // Step 2: Convert map into vector
        vector<pair<char, int>> arr;

        for (auto& [ch, count] : freq) {
            arr.push_back({ch, count});
        }

        // Step 3: Sort by frequency descending
        sort(arr.begin(), arr.end(),
            [](auto& a, auto& b) {
                return a.second > b.second;
            });

        // Step 4: Build answer
        string ans = "";

        for (auto& [ch, count] : arr) {
            ans.append(count, ch);
        }

        return ans;
    }
};