class Solution {
public:
    string customSortString(string order, string s) {

        // Frequency of characters in s
        int freq[26] = {};

        for (char ch : s) {
            freq[ch - 'a']++;
        }

        string ans = "";

        // Add characters according to order
        for (char ch : order) {

            while (freq[ch - 'a'] > 0) {
                ans += ch;
                freq[ch - 'a']--;
            }
        }

        // Add remaining characters
        for (char ch = 'a'; ch <= 'z'; ch++) {

            while (freq[ch - 'a'] > 0) {
                ans += ch;
                freq[ch - 'a']--;
            }
        }

        return ans;
    }
};