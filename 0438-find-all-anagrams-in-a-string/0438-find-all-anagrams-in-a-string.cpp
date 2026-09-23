class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> ans;

        if (p.length() > s.length())
            return ans;

        vector<int> freqP(26, 0);
        vector<int> freqWindow(26, 0);

        // Frequency of p
        for (char ch : p) {
            freqP[ch - 'a']++;
        }

        int k = p.length();

        // Sliding window
        for (int i = 0; i < s.length(); i++) {

            // Add current character
            freqWindow[s[i] - 'a']++;

            // Keep window size = k
            if (i >= k) {
                freqWindow[s[i - k] - 'a']--;
            }

            // Check anagram
            if (i >= k - 1 && freqWindow == freqP) {
                ans.push_back(i - k + 1);
            }
        }

        return ans;
    }
};