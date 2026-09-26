class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {

        vector<int> ans;

        if (s.empty() || words.empty())
            return ans;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if (s.size() < totalLen)
            return ans;

        unordered_map<string, int> required;

        for (string word : words) {
            required[word]++;
        }

        // Try every possible starting offset
        for (int offset = 0; offset < wordLen; offset++) {

            int left = offset;
            int right = offset;

            unordered_map<string, int> window;

            int count = 0;

            while (right + wordLen <= s.size()) {

                string word = s.substr(right, wordLen);
                right += wordLen;

                // Word doesn't exist in required list
                if (required.find(word) == required.end()) {

                    window.clear();
                    count = 0;
                    left = right;

                    continue;
                }

                // Add word to current window
                window[word]++;
                count++;

                // Too many occurrences of this word
                while (window[word] > required[word]) {

                    string leftWord = s.substr(left, wordLen);

                    window[leftWord]--;
                    left += wordLen;
                    count--;
                }

                // Found exact concatenation
                if (count == wordCount) {

                    ans.push_back(left);

                    // Move left by one word
                    string leftWord = s.substr(left, wordLen);

                    window[leftWord]--;
                    left += wordLen;
                    count--;
                }
            }
        }

        return ans;
    }
};