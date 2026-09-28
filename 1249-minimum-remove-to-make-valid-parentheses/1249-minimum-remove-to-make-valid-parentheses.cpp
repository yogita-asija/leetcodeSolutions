class Solution {
public:
    string minRemoveToMakeValid(string s) {

        stack<int> st;

        // Store indices that need to be removed
        unordered_set<int> remove;

        for (int i = 0; i < s.length(); i++) {

            if (s[i] == '(') {

                st.push(i);

            }
            else if (s[i] == ')') {

                if (!st.empty()) {

                    // Match this ')' with '('
                    st.pop();

                }
                else {

                    // No '(' available
                    remove.insert(i);
                }
            }
        }

        // Remaining '(' are unmatched
        while (!st.empty()) {

            remove.insert(st.top());
            st.pop();
        }

        // Build answer
        string ans;

        for (int i = 0; i < s.length(); i++) {

            if (remove.find(i) == remove.end()) {

                ans += s[i];
            }
        }

        return ans;
    }
};