class Solution {
public:

    bool isPalindrome(string &s, int l, int r) {

        while (l < r) {

            if (s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }

    vector<vector<int>> palindromePairs(vector<string>& words) {

        unordered_map<string, int> mp;

        // Store word -> index
        for (int i = 0; i < words.size(); i++) {
            mp[words[i]] = i;
        }

        vector<vector<int>> ans;

        for (int i = 0; i < words.size(); i++) {

            string word = words[i];

            int n = word.size();

            for (int j = 0; j <= n; j++) {

                // LEFT = [0 ... j-1]
                // RIGHT = [j ... n-1]

                string left = word.substr(0, j);
                string right = word.substr(j);

                // CASE 1:
                // left is palindrome
                // Need reverse(right)

                if (isPalindrome(word, 0, j - 1)) {

                    string revRight = right;
                    reverse(revRight.begin(), revRight.end());

                    if (mp.count(revRight) &&
                        mp[revRight] != i) {

                        ans.push_back({
                            mp[revRight],
                            i
                        });
                    }
                }

                // CASE 2:
                // right is palindrome
                // Need reverse(left)

                if (j != n &&
                    isPalindrome(word, j, n - 1)) {

                    string revLeft = left;
                    reverse(revLeft.begin(), revLeft.end());

                    if (mp.count(revLeft) &&
                        mp[revLeft] != i) {

                        ans.push_back({
                            i,
                            mp[revLeft]
                        });
                    }
                }
            }
        }

        return ans;
    }
};