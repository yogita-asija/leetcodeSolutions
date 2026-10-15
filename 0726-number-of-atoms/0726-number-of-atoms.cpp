
class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> st;
        st.push(map<string, int>());

        int n = formula.size();
        int i = 0;

        while (i < n) {
            if (formula[i] == '(') {
                st.push(map<string, int>());
                i++;
            }
            else if (formula[i] == ')') {
                map<string, int> group = st.top();
                st.pop();
                i++;

                int multiplier = 0;

                while (i < n && isdigit(formula[i])) {
                    multiplier = multiplier * 10
                               + (formula[i] - '0');
                    i++;
                }

                if (multiplier == 0)
                    multiplier = 1;

                for (auto &atom : group) {
                    st.top()[atom.first] +=
                        atom.second * multiplier;
                }
            }
            else {
                string atom = "";
                atom += formula[i++];

                while (i < n && islower(formula[i])) {
                    atom += formula[i++];
                }

                int count = 0;

                while (i < n && isdigit(formula[i])) {
                    count = count * 10 + (formula[i] - '0');
                    i++;
                }

                if (count == 0)
                    count = 1;

                st.top()[atom] += count;
            }
        }

        map<string, int> result = st.top();
        string ans = "";

        for (auto &atom : result) {
            ans += atom.first;

            if (atom.second > 1)
                ans += to_string(atom.second);
        }

        return ans;
    }
};
